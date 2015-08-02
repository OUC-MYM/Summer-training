#include <iostream>
using namespace std;

long long prime[50000];
long long v[100000];
void primelist()
{
    long long num=0;
    for(long long i=2; i<=50000; i++)
        if(!v[i])
        {
            prime[num++]=i;
            for(long long j=2*i; j<=50000; j=j+i)
                v[j]=1;
        }
}

long long enlerFun(long long n)
{
    long long count = n;
    for(long long i = 0; prime[i]*prime[i]<=n; i++)
        if(n % prime[i] == 0)
        {
            count = count - count / prime[i];
            while(n % prime[i] == 0)
                n = n / prime[i];
        }
    if(n>1)
        count = count - count / n;
    return count;
}

int main()
{
    primelist();
    long long N;
    while(cin >> N)
    {
        long long ans=0;
        for(long long i=1; i*i<=N; i++)
            if(N%i==0)
            {
                ans=ans+i*enlerFun(N/i);
                if(i*i==N)
                    continue;
                ans=ans+N/i*enlerFun(i);
            }
        cout << ans << endl;
    }
    return 0;
}
