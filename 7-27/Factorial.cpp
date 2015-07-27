#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long ans=0;
        long long N;
        cin >> N;
        for(long long i=5; i<=N; i=i*5)
            ans=ans+N/i;
        cout << ans << endl;
    }
    return 0;
}
