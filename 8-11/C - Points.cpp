#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int N,M;
int num[200010];
set <int> num_y[200010];

struct point
{
    char cmd[20];
    int x;
    int y;
} p[200010];

struct node
{
    int MAX;
} tree[200010*4];

void build(int left,int right,int root)
{
    if(left==right)
    {
        tree[root].MAX=-1;
        return;
    }
    int mid=(left+right)/2;
    build(left,mid,root*2);
    build(mid+1,right,root*2|1);
    tree[root].MAX=max(tree[root*2].MAX,tree[root*2+1].MAX);
}

void update(int left,int right,int root,int pos)
{
    if(left==right)
    {
        if(!num_y[pos].empty())
            tree[root].MAX=*(--num_y[pos].end());
        else tree[root].MAX=-1;
        return;
    }
    int mid=(left+right)/2;
    if (pos>mid)
        update(mid+1,right,root*2+1,pos);
    else
        update(left,mid,root*2,pos);
    tree[root].MAX=max(tree[root*2].MAX,tree[root*2+1].MAX);
}

int find(int left,int right,int root,int L,int R,int num)
{
    if(tree[root].MAX<=num||L>R)
        return -1;
    if(left==right)
        return left;
    int mid=(left+right)/2;
    if(R<=mid)
        return find(left,mid,root*2,L,R,num);
    else if(L>mid)
        return find(mid+1,right,root*2+1,L,R,num);
    else
    {
        int temp=find(left,mid,root*2,L,mid,num);
        if (temp!=-1)
            return temp;
        else
            return find(mid+1,right,root*2+1,mid+1,R,num);
    }
}

int main()
{
    scanf("%d",&N);

    for(int i=0; i<N; i++)
    {
        scanf("%s%d%d",p[i].cmd,&p[i].x,&p[i].y);
        num[i]=p[i].x;
    }

    sort(num,num+N);
    M=unique(num,num+N)-num;
    build(0,M-1,1);

    for(int i=0; i<N; i++)
    {
        int pos=lower_bound(num,num+M,p[i].x)-num;
        if(p[i].cmd[0]=='a')
        {
            num_y[pos].insert(p[i].y);
            update(0,M-1,1,pos);
        }
        if(p[i].cmd[0]=='r')
        {
            num_y[pos].erase(p[i].y);
            update(0,M-1,1,pos);
        }
        if(p[i].cmd[0]=='f')
        {
            int ans=find(0,M-1,1,pos+1,M-1,p[i].y);
            if(ans==-1)
                printf("-1\n");
            else
                printf("%d %d\n",num[ans],*num_y[ans].upper_bound(p[i].y));
        }
    }
}
