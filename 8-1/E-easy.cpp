#include <iostream>
#include <cstdio>
using namespace std;

int ans;

struct node
{
    int left,right,sum;
} tree[1000000];

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    if(left==right)
    {
        scanf("%d",&tree[root].sum);
        return;
    }
    int mid=(tree[root].left+tree[root].right)/2;
    build(left,mid,root*2);
    build(mid+1,right,root*2|1);
    tree[root].sum=tree[root*2].sum+tree[root*2|1].sum;
}

void query(int left,int right,int root,int L,int R)
{
    if(L<=left&&right<=R)
    {
        ans=ans+tree[root].sum;
        return;
    }
    int mid=(tree[root].left+tree[root].right)/2;
    if(R<=mid)
        query(left,mid,root*2,L,R);
    else if(L>mid)
        query(mid+1,right,root*2|1,L,R);
    else
    {
        query(left,mid,root*2,L,R);
        query(mid+1,right,root*2|1,L,R);
    }
}


void change(int left,int right,int root,int pos,int num)
{
    if(left==right)
    {
        tree[root].sum=tree[root].sum+num;
        return;
    }
    int mid=(tree[root].left+tree[root].right)/2;
    if(pos<=mid)
        change(left,mid,root*2,pos,num);
    else
        change(mid+1,right,root*2|1,pos,num);
    tree[root].sum=tree[root*2].sum+tree[root*2|1].sum;
}



int main()
{
    int T,N=0;
    cin >> T;
    while(T--)
    {
        N++;
        cout << "Case " << N << ":" << endl;

        int n;
        cin >> n;
        build(1,n,1);

        char cmd[20];
        while(~scanf("%s",cmd))
        {
            if(cmd[0]=='E')
                break;
            int a,b;
            scanf("%d %d",&a,&b);
            if(cmd[0]=='Q')
                {
                    ans=0;
                    query(1,n,1,a,b);
                    printf("%d\n",ans);
                }
            if(cmd[0]=='S')
                change(1,n,1,a,-b);
            if(cmd[0]=='A')
                change(1,n,1,a,b);
        }
    }
    return 0;
}
