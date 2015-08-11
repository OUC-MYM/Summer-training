#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int m,n,t;
int dp1[10010];
int dp2[10010];

int main()
{
    while(cin >> m >> n >> t)
    {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,-9999,sizeof(dp2));
        dp2[m]=1,dp2[n]=1;
        dp2[0]=0;
        for(int k=1; k<=2; k++)
        {
            int i;
            k==1?i=m:i=n;
            for(int j=i; j<=t; j++)
            {
                dp1[j]=max(dp1[j],dp1[j-i]+i);
                dp2[j]=max(dp2[j],dp2[j-i]+1);
            }
        }
        if(dp1[t]==t)
        {
            cout << dp2[t] << endl;
            continue;
        }
        for(int i=t-1; i>=0; i--)
            if(dp1[i]==i)
            {
                cout << dp2[i] << " " << t-dp1[t] << endl;
                break;
            }
    }
    return 0;
}
