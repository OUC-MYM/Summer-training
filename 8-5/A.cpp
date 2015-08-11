#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int M,N;

struct warehouse
{
    int j;
    int f;
};

bool cmp(warehouse a,warehouse b)
{
    return (a.j*1.0/a.f)>(b.j*1.0/b.f);
}

int main()
{
    while(cin >> M >> N)
    {
        if(M==-1&&N==-1)
            break;

        warehouse p[N];
        double ans=0;

        for(int i=0; i<N; i++)
            cin >> p[i].j >> p[i].f;

        sort(p,p+N,cmp);
        for(int i=0; i<N; i++)
        {
            if(M>=p[i].f)
            {
                M=M-p[i].f;
                ans=ans+p[i].j;
            }
            else
            {
                ans=ans+(M*1.0)*1.0/p[i].f*1.0*1.0*p[i].j;
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
