#include <iostream>

using namespace std;

int dp[7500];
int cent[]= {1,5,10,25,50};

void solv()
{
    dp[0]=1;
    for(int j=0; j<5; j++)
        for(int i=0; i<7500; i++)
            dp[i+cent[j]]=dp[i+cent[j]]+dp[i];
}

int main()
{
    cin.sync_with_stdio(false);
    solv();
    int N;
    while(cin >> N)
    {
        cout << dp[N] << endl;
    }
    return 0;
}
