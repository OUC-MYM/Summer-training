#include <iostream>

using namespace std;

int exGCD(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exGCD(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int main()
{
    long long x,y,m,n,L;
    cin >> x >> y >> m >> n >> L;
    long long X,Y;
    long long gcd=exGCD(L,n-m,X,Y);
    if((x-y)%gcd!=0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    long long d=(x-y)/gcd;
    Y=Y*d;
    while(Y<0)
        Y=Y%(L/gcd)+L/gcd;
    cout << Y%(L/gcd) << endl;
}
