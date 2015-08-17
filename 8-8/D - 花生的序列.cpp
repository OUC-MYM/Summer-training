#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int dp1[3010],dp2[3010];
char str[6020];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        cin >> str+1;
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        dp1[0]=dp2[0]=1;

        for(int i=0; i<=n; i++)
            for (int j=0; j<=n; j++)
            {
                if(i==0 && j==0)
                    continue;
                int sum=0;
                if(str[i+j]=='W')
                {
                    if(i&1)
                        sum = (sum+dp1[j])%MOD;
                    if(j&1)
                        sum = (sum+dp2[j-1])%MOD;

                    dp1[j]=dp2[j]=sum%MOD;
                }
                if(str[i+j]=='B')
                {
                    if(i>0 && (i&1)==0)
                        sum = (sum+dp1[j])%MOD;
                    if(j>0 && (j&1)==0)
                        sum = (sum+dp2[j-1])%MOD;

                    dp1[j]=dp2[j]=sum%MOD;
                }
            }

        cout << dp1[n] << endl;
    }
    return 0;
}
