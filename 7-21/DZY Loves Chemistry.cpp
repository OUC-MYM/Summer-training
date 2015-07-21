#include <iostream>
using namespace std;
int n,m;
int num[60];
int pre[60];
int sum[60];

int find (int x)
{
    if(pre[x]==x)
        return x;
    else
        return find(pre[x]);
}

int main()
{
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        {
            pre[i]=i;
            sum[i]=1;
        }

    int a,b;
    for(int i=1; i<=m; i++)
    {
        cin >> a >> b;

        int x=find(a);
        int y=find(b);

        if(x!=y)
        {
            pre[x]=y;
            sum[y]=sum[x]+sum[y];
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
        if(pre[i]==i)
            ans=ans+sum[i]-1;

        unsigned long long all=1;
        for(int i=0;i<ans;i++)
            all=all*2;

    cout << all << endl;
    return 0;
}
