#include <iostream>
using namespace std;

int N,M,Q;

struct node
{
    int sum,add;
} tree[100000*4];

void PushUP(int root)
{
    tree[root].sum=tree[root*2].sum+tree[root*2|1].sum;
}

void PushDown(int root,int m)
{
    if (tree[root].add)
    {
        tree[root*2].add=tree[root*2].add+tree[root].add;
        tree[root*2|1].add=tree[root*2|1].add+tree[root].add;
        tree[root*2].sum=tree[root*2].sum+tree[root].add*(m-(m/2));
        tree[root*2|1].sum=tree[root*2|1].sum+tree[root].add*(m/2);
        tree[root].add=0;
    }
}



void build(int left,int right,int root)
{
    tree[root].add=0;
    if(left==right)
    {
        cin >> tree[root].sum;
        return;
    }
    int mid=(left+right)/2;
    build(left,mid,root*2);
    build(mid+1,right,root*2|1);
    PushUP(root);
}

int query(int left,int right,int root,int L,int R)
{
    if(L<=left&&right<=R)
        return tree[root].sum;
    PushDown(root,right-left+1);
    int mid=(left+right)/2;
    int ans=0;
    if(L<=mid)
        ans=ans+query(left,mid,root*2,L,R);
    if(R>mid)
        ans=ans+query(mid+1,right,root*2|1,L,R);
    return ans;
}

void update(int left,int right,int root,int L,int R,int num)
{
    if(L<=left&&right<=R)
    {
        tree[root].add=tree[root].add+num;
        tree[root].sum=tree[root].sum+num*(right-left+1);
        return;
    }
    PushDown(root,right-left+1);
    int mid=(left+right)/2;
    if(L<=mid)
        update(left,mid,root*2,L,R,num);
    if(mid<R)
        update(mid+1,right,root*2|1,L,R,num);
    PushUP(root);
}

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> M >> Q)
    {
        build(1,N,1);
        int X;

        while(Q--)
        {
            cin >> X;
            cout << query(1,N,1,X,X+M-1) << endl;
            update(1,N,1,X,X+M-1,-1);
        }
    }
    return 0;
}
