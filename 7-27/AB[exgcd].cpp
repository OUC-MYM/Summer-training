#include <iostream>
#define MOD 9973
using namespace std;

int n,A,B;

int exGCD(int a,int b,int &x,int &y)
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
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> B;
        int x,y;
        exGCD(B,MOD,x,y);
        x=x*n;
        while(x<0)
            x=x+MOD;
        cout << x%MOD << endl;
    }
    return 0;
}
