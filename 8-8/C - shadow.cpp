#include <iostream>
using namespace std;
int N,K;
int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> K)
    {
        int sum=0;
        int a;
        for(int i=1; i<=N; i++)
            cin >> a,sum=sum+a;
        while(K--)
            cin >> a;
        while(--N)
            cin >> a >> a;
        cout << sum << endl;
    }
    return 0;
}
