#include <iostream>
#include <cstring>
using namespace std;

int len1,len2;

int dp[110][110];

int solve(int a[],int b[])
{
    memset(dp,0,sizeof(dp));
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
    while(cin >> len1 >> len2 && (len1||len2))
    {
        int a[len1];
        for(int i=0;i<len1;i++)
            cin >> a[i];
        int b[len2];
        for(int i=0;i<len2;i++)
            cin >> b[i];
        cout << "Twin Towers #" << ++N << endl;
        cout << "Number of Tiles : " << solve(a,b) << endl << endl;
    }
    return 0;
}
