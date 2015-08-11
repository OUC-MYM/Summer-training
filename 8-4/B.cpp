#include <iostream>
#include <cstring>
using namespace std;

long long h[100010];
long long L[100010];
long long R[100010];

int main()
{
    cin.sync_with_stdio(false);
    long long N;
    while(cin >> N && N)
    {
        memset(h,-1,sizeof(h));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        long long ans=0;

        for(long long i=1; i<=N; i++)
        {
            cin >> h[i];
            L[i]=R[i]=i;
        }

        for(long long i=1; i<=N; i++)
            while(h[L[i]-1]>=h[i])
                L[i]=L[L[i]-1];


        for(long long i=N; i>=1; i--)
            while(h[R[i]+1]>=h[i])
                R[i]=R[R[i]+1];

        for(long long i=1; i<=N; i++)
            ans = max(ans,h[i]*(R[i]-L[i]+1));

        cout << ans <<endl;
    }
    return 0;
}
