#include <iostream>
#define MOD 9973
using namespace std;

long long n,B;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> B;

        for(int i=0; i<MOD; i++)
            if((B%MOD*i)%MOD==n)
            {
                cout << i << endl;
                break;
            }
    }
    return 0;
}
