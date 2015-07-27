#include <iostream>

using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int temp1=N/2;
        int temp2=N-temp1;
        cout << (temp1-1)*temp1/2+(temp2-1)*temp2/2 << endl;
    }
    return 0;
}
