#include <iostream>
using namespace std;

long long N,Q;

struct node
{
    long long sum,add;
} tree[100000*4];

void PushUP(long long root)
{
    tree[root].sum=tree[root*2].sum+tree[root*2|1].sum;
}

void PushDown(long long root,long long m)
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



void build(long long left,long long right,long long root)
{
    tree[root].add=0;
    if(left==right)
    {
        cin >> tree[root].sum;
        return;
    }
    long long mid=(left+right)/2;
    build(left,mid,root*2);
    build(mid+1,right,root*2|1);
    PushUP(root);
}

long long query(long long left,long long right,long long root,long long L,long long R)
{
    if(L<=left&&right<=R)
        return tree[root].sum;
    PushDown(root,right-left+1);
    long long mid=(left+right)/2;
    long long ans=0;
    if(L<=mid)
        ans=ans+query(left,mid,root*2,L,R);
    if(R>mid)
        ans=ans+query(mid+1,right,root*2|1,L,R);
    return ans;
}

void update(int left,int right,int root,int L,int R,long long num)
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
    while(cin >> N >> Q)
    {
        build(1,N,1);

        long long a,b,c;
        char temp;

        while(Q--)
        {
            cin >> temp;
            if(temp=='Q')
            {
                cin >> a >> b;
                cout << query(1,N,1,a,b) << endl;
            }
            else
            {
                cin >> a >> b >> c;
                update(1,N,1,a,b,c);
            }
        }
    }
    return 0;
}
