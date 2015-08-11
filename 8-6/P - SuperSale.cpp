#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,G,ans;
int p[1010], w[1010];
int dp[1010];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ans=0;
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> p[i] >> w[i];

        cin >> G;
        while(G--)
        {
            memset(dp, 0, sizeof(dp));
            int W;
            cin >> W;
            for(int i=0; i<N; i++)
                for(int j=W; j>=w[i]; j--)
                    dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
            ans=ans+dp[W];
        }
        cout << ans << endl;
    }
    return 0;
}
