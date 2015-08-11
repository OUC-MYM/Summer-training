#include <iostream>

using namespace std;

long long dp[20][2];
long long s,e;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s >> e;
        dp[1][1]=10;
        dp[1][0]=0;
        dp[2][0]=99-10+1;
        dp[2][1]=0;
        for(int i=3; i<=17; i++)
            ;
    }
    return 0;
}
