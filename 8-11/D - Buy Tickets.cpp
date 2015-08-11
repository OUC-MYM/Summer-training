#include <iostream>
using namespace std;

struct node
{
    int sum;
    int id;
} tree[200000*5];

struct people
{
    int pos;
    int id;
} p[200010];

void PushUP(int root)
{
    tree[root].sum=tree[root*2].sum+tree[root*2|1].sum;
}

void build(int left,int right,int root)
{
    if(left==right)
    {
        tree[root].sum=1;
        return;
    }
    int mid=(left+right)/2;
    build(left,mid,root*2);
    build(mid+1,right,root*2|1);
    PushUP(root);
}

void inserts(int left,int right,int root,int pos,int id)
{
    if(left==right)
    {
        tree[root].sum=0;
        tree[root].id=id;
        return;
    }
    int mid=(left+right)/2;
    if(tree[root*2].sum>=pos)
        inserts(left,mid,root*2,pos,id);
    else
        inserts(mid+1,right,root*2|1,pos-tree[root*2].sum,id);
    PushUP(root);
}

void print(int left,int right,int root)
{
    if(left==right)
    {
        cout << tree[root].id << " ";
        return;
    }
    int mid=(left+right)/2;
    print(left,mid,root*2);
    print(mid+1,right,root*2|1);
}

int main()
{
    cin.sync_with_stdio(false);
    int N;
    while(cin >> N)
    {
        build(1,N,1);

        for(int i=1; i<=N; i++)
            cin >> p[i].pos >> p[i].id;

        for(int i=N; i>0; i--)
            inserts(1,N,1,p[i].pos+1,p[i].id);

        print(1,N,1);
        cout << endl;
    }
    return 0;
}
