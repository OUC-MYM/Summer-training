#include <iostream>

using namespace std;

int dp[100100];

int main()
{
    dp[0]=0;
    for(int i=1; i<=100010; i++)
        if(i%7==6||i%7==0)
            dp[i]=dp[i-1]+1;
        else
            dp[i]=dp[i-1];
    int N;
    while(cin >> N)
    {
        cout << dp[N] << endl;
    }
    return 0;
}
