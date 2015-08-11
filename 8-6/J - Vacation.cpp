#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int len1,len2;

int dp[110][110];

int solve(char a[],char b[])
{
    memset(dp,0,sizeof(dp));
    len1=strlen(a);
    len2=strlen(b);
    for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[len1][len2];
}

int main()
{
    int N=0;
    char a[110],b[110];
    while(gets(a))
    {
        if(a[0]=='#')
            break;
        gets(b);
        printf("Case #%d: you can visit at most %d cities.\n",++N,solve(a,b));
    }
    return 0;
}
