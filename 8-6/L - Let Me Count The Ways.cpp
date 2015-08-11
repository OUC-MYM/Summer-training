#include <iostream>
#include <cstdio>
using namespace std;

long long dp[30100];
int cent[]= {1,5,10,25,50};

void solv()
{
    dp[0]=1;
    for(int j=0; j<5; j++)
        for(int i=0; i<=30000; i++)
            dp[i+cent[j]]=dp[i+cent[j]]+dp[i];
}

int main()
{
    solv();
    int N;
    while(cin >> N)
    {
        if(dp[N]==1)
            printf("There is only 1 way to produce %d cents change.\n",N);
        else
            printf("There are %lld ways to produce %d cents change.\n",dp[N],N);
    }
    return 0;
}
