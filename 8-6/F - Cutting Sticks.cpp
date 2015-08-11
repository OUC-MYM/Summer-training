#include <iostream>
#include <cstring>
using namespace std;

int l,n;
int cut[55];
int dp[1010][1010];

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> l && l)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> cut[i];
        cut[0]=0;
        cut[n+1]=l;
        memset(dp,0,sizeof(dp));

        for(int z=1; z<=n+1; z++)
            for(int i=0; i<=n; i++)
            {
                int j=i+z;
                if(j>n+1)
                    break;
                int MIN=1<<30;
                for(int k=i+1; k<j; k++)
                    MIN=min(MIN,dp[i][k]+dp[k][j]+cut[j]-cut[i]);
                if(MIN!=1<<30)
                    dp[i][j]=MIN;
            }
        cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
    }
    return 0;
}
