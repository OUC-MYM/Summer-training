#include <iostream>

using namespace std;

int n;
int dp[35][3];

void solv()
{
    dp[2][0]=3;
    dp[2][1]=2;
    for(int i=4; i<32; i=i+2)
    {
        dp[i][0]=dp[i-2][0]*3+dp[i-2][1];
        dp[i][1]=dp[i-2][0]*2+dp[i-2][1];
    }
}

int main()
{
    solv();
    while(cin >> n && n!=-1)
    {
        if(n==0)
        {
            cout << "1" << endl;
            continue;
        }
        if(n%2)
            cout << "0" << endl;
        else
            cout << dp[n][0] << endl;
    }
    return 0;
}
