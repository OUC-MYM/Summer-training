#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define INF 1<<30
using namespace std;

int dp[1010];

struct blocks
{
    int x;
    int y;
    int h;
} B[1010];

bool cmp(blocks a,blocks b)
{
    return (long long)a.x*(long long)a.y >= (long long)b.x*(long long)b.y;
}

int main()
{
    int T=0;
    int N;
    while(cin >> N && N)
    {
        memset(dp,0,sizeof(dp));
        int xx,yy,zz;
        B[0].x=INF,B[0].y=INF,B[0].h=0;
        int cnt=1;
        for(int i=0; i<N; i++)
        {
            cin >> xx >> yy >> zz;
            B[cnt].x=xx,B[cnt].y=yy,B[cnt++].h=zz;
            B[cnt].x=xx,B[cnt].y=zz,B[cnt++].h=yy;
            B[cnt].x=yy,B[cnt].y=xx,B[cnt++].h=zz;
            B[cnt].x=yy,B[cnt].y=zz,B[cnt++].h=xx;
            B[cnt].x=zz,B[cnt].y=xx,B[cnt++].h=yy;
            B[cnt].x=zz,B[cnt].y=yy,B[cnt++].h=xx;
        }

        sort(B+1,B+cnt,cmp);

        for(int i=0; i<cnt; i++)
            for(int j=0; j<cnt; j++)
                if(B[i].x<B[j].x && B[i].y<B[j].y)
                    dp[i]=max(dp[i],dp[j]+B[i].h);

        int ans=0;
        for(int i=1; i<cnt; i++)
            ans=max(ans,dp[i]);

        printf("Case %d: maximum height = %d\n",++T,ans);
    }
    return 0;
}
