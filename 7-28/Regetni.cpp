#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long N;
long long sum[2][2];

int main()
{
    int T;
    scanf("%I64d",&T);
    int scenario=0;
    int a,b;
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        scenario++;


        scanf("%I64d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d%d",&a,&b);
            a=(a+100000)%2;
            b=(b+100000)%2;
            sum[a][b]++;
        }

        long long ans=N*(N-1)*(N-2)/6;
        ans=ans-sum[0][0]*sum[0][1]*sum[1][0];
        ans=ans-sum[0][0]*sum[0][1]*sum[1][1];
        ans=ans-sum[0][0]*sum[1][0]*sum[1][1];
        ans=ans-sum[0][1]*sum[1][0]*sum[1][1];
        printf("Scenario #%d:\n",scenario);
        printf("%I64d\n\n",ans);
    }
    return 0;
}
