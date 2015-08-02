#include <iostream>
#include <cmath>
using namespace std;

unsigned long long N;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        double temp;
        temp=N*log10(N);
        temp=temp-(unsigned long long)temp;
        cout << int(pow(10,temp)) << endl;
    }
    return 0;
}
