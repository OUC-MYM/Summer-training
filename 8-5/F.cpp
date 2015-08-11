#include <iostream>
#include <cmath>
#define INF 1<<30
using namespace std;

int N;
long long dp[65];

void solv()
{
    dp[1]=1;
    dp[2]=3;
    for(int i=3; i<65; i++)
    {
        long long min=INF;
        for(int j=1; j<i; j++)
            if(min>2*dp[j]+pow(2,i-j)-1)
                min=2*dp[j]+pow(2,i-j)-1;
        dp[i]=min;
    }
}

int main()
{
    solv();
    while(cin >> N)
    {
        cout << dp[N] << endl;
    }
    return 0;
}
