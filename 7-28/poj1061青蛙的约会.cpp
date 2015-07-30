#include <iostream>

using namespace std;

long long exGCD(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long r=exGCD(b,a%b,x,y);
    long long t=x;
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
    Y=Y*(x-y)/gcd;
    Y=Y%(L/gcd);
    while(Y<0)
        Y=Y+L/gcd;
    cout << Y%(L/gcd) << endl;
}
