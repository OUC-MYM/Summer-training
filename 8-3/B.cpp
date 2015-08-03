#include <iostream>
#include <cmath>
#include <cstring>
#define INF 1<<30
using namespace std;

int n,k;
int d[210],dis[210][210];
int dp[210][35];

int main()
{
    int N=0;
    while(cin >> n >> k && (n||k))
    {
        memset(d,0,sizeof(d));
        memset(dis,0,sizeof(dis));
        memset(dp,0,sizeof(dp));

        N++;
        cout << "Chain " << N << endl << "Total distance sum = ";

        for(int i=1; i<=n; i++)
            cin >> d[i];

        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
            {
                dis[i][j]=0;
                for(int k=i; k<=j; k++)
                    dis[i][j]=dis[i][j]+abs(d[k]-d[(i+j)/2]);
                dis[j][i]=dis[i][j];
            }

        for(int i=1; i<=n; i++)
            dp[i][1]=dis[1][i];

        for(int i=1; i<=n; i++)
            for(int j=2; j<=k; j++)
            {
                dp[i][j]=INF;
                for(int k=j-1; k<=i-1; k++)
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+dis[k+1][i]);
            }

        cout << dp[n][k] << endl << endl;
    }
    return 0;
}
