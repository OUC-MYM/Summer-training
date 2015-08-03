#include <iostream>
#include <cstring>
using namespace std;

int M,N;

int dp[11][11];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> M >> N;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=M; i++)
            for(int j=0; j<=N; j++)
                if(i==0||i==1||j==1)
                    dp[i][j]=1;

        for(int i=2; i<=M; i++)
            for(int j=2; j<=N; j++)
                i>=j?dp[i][j]=dp[i][j-1]+dp[i-j][j]:dp[i][j]=dp[i][j-1];

        cout << dp[M][N] << endl;
    }
    return 0;
}
