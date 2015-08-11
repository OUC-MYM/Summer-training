#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int len1,len2;

int dp[110][10010];

int solve(char a[],char b[])
{
    memset(dp,0,sizeof(dp));
    len1=strlen(a);
    len2=strlen(b);

    for(int i=0; i<=len2; i++)
        dp[0][i]=1;

    for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            else
                dp[i][j]=dp[i][j-1];
        }
    return dp[len1][len2];
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        char a[110],b[10010];
        cin >> b;
        cin >> a;
        cout << solve(a,b) << endl;
    }
    return 0;
}
