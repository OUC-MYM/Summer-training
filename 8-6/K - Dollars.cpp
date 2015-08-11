#include <iostream>
#include <cstdio>
using namespace std;

long long dp[40010];
int cent[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

void solv()
{
    dp[0]=1;
    for(int j=0; j<11; j++)
        for(int i=0; i<=30000; i++)
            dp[i+cent[j]]=dp[i+cent[j]]+dp[i];
}

int main()
{
    solv();
    int N;
    double temp;
    while(cin >> temp)
    {
        N=int(temp*100+0.5);
        if(N==0)
            break;
        printf("%6.2lf%17lld\n",temp,dp[N]);
    }
    return 0;
}
