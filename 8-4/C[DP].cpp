#include <iostream>
#include <cstring>
using namespace std;

string str;
int len;
int dp[110][2];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        cin >> str;
        len=str.length();
        dp[0][1]=1;
        for(int i=1; i<=len; i++)
            if(str[i-1]>='A'&&str[i-1]<='Z')
            {
                dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
                dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
            }
            else
            {
                dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
                dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
            }
        dp[len][1]++;
        cout << min(dp[len][0],dp[len][1]) << endl;
    }
    return 0;
}
