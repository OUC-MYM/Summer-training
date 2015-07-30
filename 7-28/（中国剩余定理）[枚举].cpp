#include <iostream>
#include <cstdio>
using namespace std;

int p,e,i,d;

int main()
{
    int N=0;
    while(cin >> p >> e >> i >> d)
    {
        N++;
        if(p==-1&&e==-1&&i==-1&&d==-1)
            break;

        p=p%23;
        e=e%28;
        i=i%33;

        for(int ans=d+1; ans<=21252+d; ans++)
            if(ans%23==p&&ans%28==e&&ans%33==i)
            {
                printf("Case %d: the next triple peak occurs in %d days.\n",N,ans-d);
                break;
            }
    }
    return 0;
}
