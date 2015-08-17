#include<iostream>
#include<cstring>
using namespace std;

int dp[15][15];
string s1,s2;

int main()
{
    int len1,len2;
    while(cin >> s1 >> s2)
    {
        len1=s1.length();
        len2=s2.length();
        memset(dp,1<<6,sizeof dp);
        dp[0][0]=0;

        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i+1<=len1)
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
                if(j+1<=len2)
                    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
                if(s1[i]==s2[j])
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                if(i>=len1&&j<=len2-j)
                {
                    int flag=1;
                    for(int k=0; k<j; k++)
                        if(s2[k]!=s2[k+j])
                        {
                            flag=0;
                            break;
                        }
                    if(flag)
                        dp[i][j+j]=min(dp[i][j+j],dp[i][j]+1);
                }
            }
        }

        if(dp[len1][len2]<=15)
            cout << dp[len1][len2] << endl;
        else
            cout << "more than 15 operations." << endl;
    }
    return 0;
}
