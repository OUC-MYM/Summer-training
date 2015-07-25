#include <iostream>

using namespace std;

long long sx,sy,ex,ey;

//int a[310];
//int b[310];
//int c[310];
long long a,b,c;

long long fun(long x,long y)
{
    return a*x+b*y+c;
}

int main()
{
    cin >> sx >> sy >> ex >> ey;
    int n;
    cin >> n;

    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b >> c;
        if(fun(sx,sy)>0&&fun(ex,ey)<0||fun(sx,sy)<0&&fun(ex,ey)>0)
            ans++;
    }

    cout << ans << endl;
}
