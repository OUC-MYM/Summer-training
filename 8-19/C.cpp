#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 1<<30
#define MAXN 500
using namespace std;

int n,m,s,v;
int N1,N2;
bool map[MAXN][MAXN];
bool vis[MAXN];
int father[MAXN];
struct point
{
    double x;
    double y;
};

point  gop[MAXN],hole[MAXN];

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool link(int n)
{
    for(int i=1; i<=N2; i++)
        if(map[n][i] && !vis[i])
        {
            vis[i]=1;
            if(father[i]==0||link(father[i]))
            {
                father[i]=n;
                return true;
            }
        }
    return false;
}

int solv()
{
    N1=n;
    N2=m;
    int cnt=0;
    memset(father,0,sizeof(father));
    for(int i=1; i<=N1; i++)
    {
        memset(vis,0,sizeof(vis));
        if(link(i))
            cnt++;
    }
    return cnt;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> n >> m >> s >> v)
    {
        memset(map,0,sizeof(map));
        for(int i=1; i<=n; i++)
            cin >> gop[i].x >> gop[i].y;
        for(int i=1; i<=m; i++)
            cin >> hole[i].x >> hole[i].y;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(dis(gop[i],hole[j])<=double(s*v))
                    map[i][j]=1;

        cout << n-solv() << endl;
    }
    return 0;
}
