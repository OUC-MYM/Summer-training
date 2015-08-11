#include <iostream>
#include <cstring>
using namespace std;

int F,V;


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> F >> V)
    {
        int value[F][V];
        memset(value,0,sizeof(value));
        for(int i=0; i<F; i++)
            for(int j=0; j<V; j++)
                cin >> value[i][j];
        int dp[F][V];
        memset(dp,0,sizeof(dp));

        for(int j=0; j<V; j++)
            dp[0][j]=value[0][j];

        for(int i=1; i<F; i++)
            for(int j=i; j<V; j++)
                for(int k=i-1; k<j; k++)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+value[i][j]);

        int ans=dp[F-1][V-1];
        for(int i=F-1; i<V; i++)
            ans=max(ans,dp[F-1][i]);
        cout << ans << endl;
    }
    return 0;
}
