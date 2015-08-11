#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int coin[110];
int sum;
int dp[50000];

int solve()
{
    memset(dp,0,sizeof(dp));
    int Div=sum/2;
    for(int i=0; i<N; i++)
        for(int j=Div; j>=coin[i]; j--)
            dp[j]=max(dp[j],dp[j-coin[i]]+coin[i]);
    return abs(sum-dp[Div]-dp[Div]);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        sum=0;
        cin >> N;
        for(int i=0; i<N; i++)
        {
            cin >> coin[i];
            sum=sum+coin[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
