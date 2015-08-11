#include <iostream>
#include <cstring>
using namespace std;

int dp[25][25];

int solve(int ans[],int stu[],int len)
{
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=len; i++)
        for(int j=1; j<=len; j++)
        {
            if(ans[i-1]==stu[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return dp[len][len];
}

int main()
{
    int n;
    cin >> n;

    int ans[25]= {0};
    for(int i=1; i<=n; i++)
    {
        int temp;
        cin >> temp;
        ans[temp-1]=i;
    }

    int stu[25];
    int temp;
    while(cin >> temp)
    {
        memset(stu,0,sizeof(stu));
        stu[temp-1]=1;
        for(int i=2; i<=n; i++)
        {
            int temp;
            cin >> temp;
            stu[temp-1]=i;
        }
        cout << solve(ans,stu,n) << endl;
    }
}
