#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

double MAX(double a,double b)
{
    if(a>=b)
        return a;
    return b;
}

double dp[11000];
double Pj[110];
int Mj[110];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        double P;
        cin >> P;
        P=1-P;

        int N;
        cin >> N;

        memset(dp, 0, sizeof(dp));
        dp[0]=1;

        double sum=0;
        for(int i=1; i<=N; i++)
        {
            cin >> Mj[i] >> Pj[i];
            Pj[i]=1-Pj[i];
            sum=sum+Mj[i];
        }

        for(int i=1; i<=N; i++)
            for(int j=sum; j>=Mj[i]; j--)
                dp[j] = MAX(dp[j],dp[j-Mj[i]]*Pj[i]);

        for(int k=sum;k>=0; k--)
        {
            if(dp[k]>=P)
            {
                cout << k << endl;
                break;
            }
        }

    }
    return 0;
}
