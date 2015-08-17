#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[11][100010];
int num[11][100010];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset(dp,-999999,sizeof(dp));
        memset(num,0,sizeof(num));
        dp[5][0]=0;

        int x,t;
        while(n--)
        {
            scanf("%d%d",&x,&t);
            num[x][t]++;
        }

        for(int j=1; j<=100000; j++)
            for(int i=0; i<=10; i++)
                for(int k=-1; k<=1; k++)
                    if(i+k>=0&&i+k<=10)
                        dp[i][j]=max(dp[i][j],dp[i+k][j-1]+num[i][j]);

        int ans=0;
        for(int i=0; i<=10; i++)
            ans=max(ans,dp[i][100000]);
        printf("%d\n",ans);
    }
    return 0;
}
