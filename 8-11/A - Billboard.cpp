#include <iostream>
#include <cstdio>
using namespace std;

int h,w,n;

struct node
{
    int left;
    int right;
    int mid;
    int sum;
} tree[200000<<2];

void build(int left,int right,int root)
{
    tree[root].left=left;
    tree[root].right=right;
    tree[root].mid=(left+right)>>1;
    tree[root].sum=w;
    if(left==right)
        return;
    build(left,tree[root].mid,root<<1);
    build(tree[root].mid+1,right,root<<1|1);
}

int query(int root,int x)
{
    if(tree[root].left==tree[root].right)
    {
        tree[root].sum=tree[root].sum-x;
        return tree[root].left;
    }
    int ans;
    if(x<=tree[root<<1].sum)
        ans=query(root<<1,x);
    else
        ans=query(root<<1|1,x);
    tree[root].sum=max(tree[root<<1].sum,tree[root<<1|1].sum);
    return ans;
}

int main()
{
    int x;
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        if(h>n)
            h=n;
        build(1,h,1);
        while(n--)
        {
            scanf("%d",&x);
            if(x>tree[1].sum)
                printf("-1\n");
            else
                printf("%d\n",query(1,x));
        }
    }
    return 0;
}
