#include <iostream>
#include <cstring>
using namespace std;

int V,N;
int v[25];
int dp[50000];
int vis[25][50000];

void solve()
{
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));

    for(int i=N-1; i>=0; i--)
        for(int j=V; j>=v[i]; j--)
        {
            if(dp[j]<dp[j-v[i]]+v[i])
                vis[i][j]=1;
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }

    int i,j;
    for(i=0,j=dp[V]; i<N; i++)
    {
        if(vis[i][j])
        {
            cout << v[i] << " ";
            j=j-v[i];
        }
    }
}

int main()
{
    while(cin >> V)
    {
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> v[i];
        solve();
        cout << "sum:" << dp[V] << endl;
    }
    return 0;
}
