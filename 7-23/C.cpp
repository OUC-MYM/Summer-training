#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,d;

int islandX[1010];
int islandY[1010];

struct point
{
    double L;
    double R;
} p[1010];

bool cmp(point a,point b)
{
    return a.L<b.L;
}

int main()
{
    int T=0;
    while(++T)
    {
        int flag=0;

        cin >> n >> d;
        if(n==0&&d==0)
            break;

        for(int i=0; i<n; i++)
        {
            cin >> islandX[i] >> islandY[i];
            if(abs(islandY[i])>d)
                flag=1;
            else
            {
                p[i].L=islandX[i]-sqrt(d*d-islandY[i]*islandY[i]);
                p[i].R=islandX[i]+sqrt(d*d-islandY[i]*islandY[i]);
            }

        }

        if(flag)
        {
            printf("Case %d: %d\n",T,-1);
            continue;
        }

        int ans=1;
        sort(p,p+n,cmp);
        point temp=p[0];

        for (int i=1; i<n; i++)
        {
            if (p[i].L>temp.R)
            {
                ans++;
                temp=p[i];
            }
            else if(p[i].R<temp.R)
            {
                temp=p[i];
            }
        }

        printf("Case %d: %d\n",T,ans);
    }
    return 0;
}
