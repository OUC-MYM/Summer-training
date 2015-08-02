#include <iostream>
#include <cmath>
using namespace std;

long long prime[100000];

void primelist()
{
    long long v[100001]= {0};
    long long num=0;
    for(long long i=2; i<=100000; i++)
        if(!v[i])
        {
            prime[num++]=i;
            for(long long j=2*i; j<=100000; j=j+i)
                v[j]=1;
        }
}

long long enlerFun(long long q,long long k)
{
    if(k==0)
        return 1;
    long long ans=q-1;
    while(--k)
        ans=ans*q;
    return ans;
}

long long F(long long q,long long k)
{
    long long ans=0,temp=1;
    for(long long i=0;i<=k;i++)
        {
            ans=ans+temp*enlerFun(q,k-i);
            temp=temp*q;
        }
    return ans;
}

int main()
{
    primelist();
    long long N;
    while(cin >> N)
    {
        long long ans=1;
        for(long long i=0; prime[i]*prime[i]<=N; i++)
            if(N%prime[i]==0)
            {
                long long cnt=0;
                while(N%prime[i]==0)
                {
                    N=N/prime[i];
                    cnt++;
                }
                ans=ans*F(prime[i],cnt);
            }
        if(N>1)
            ans=ans*F(N,1);
        cout << ans << endl;
    }
    return 0;
}
