#include <iostream>
#include <cmath>
using namespace std;

int r,h;

int main()
{
    cin >> r >> h;
    int ans=h/r*2;
    if (h%r<r*1.0/2)
        ans++;
    else if(h%r<sqrt(3)*1.0/2*r)
        ans=ans+2;
    else
        ans=ans+3;
    cout << ans << endl;
    return 0;
}
