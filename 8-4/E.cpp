#include <iostream>
#include <cstring>
using namespace std;

int len;
int dp[2][5010];

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> len)
    {
        memset(dp,0,sizeof(dp));
        char str1[len+1],str2[len+1];
        for(int i=0; i<len; i++)
        {
            cin >> str1[i];
            str2[len-1-i]=str1[i];
        }
        for(int i=1; i<=len; i++)
            for(int j=1; j<=len; j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i%2][j]=dp[1-i%2][j-1]+1;
                else
                    dp[i%2][j]=max(dp[1-i%2][j],dp[i%2][j-1]);
            }
        cout << len-dp[len%2][len] << endl;
    }
    return 0;
}
