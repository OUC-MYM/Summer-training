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
#define INF 0x3f3f3f3f
using namespace std;

int N1,N2;
int Q,M;
bool v[210][210];
int map[25][25];
bool vis[210];
int father[210];
struct point
{
    int id;
    int s;
    int d;
} p[210];

bool link(int n)
{
    for(int i=1; i<=N2; i++)
        if(v[n][i]&&!vis[i])
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
    N1=N2=M;
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

void floyd()
{
    for(int k=1; k<=Q; k++)
        for(int i=1; i<=Q; i++)
            for(int j=1; j<=Q; j++)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}




int main()
{
    cin.sync_with_stdio(false);
    while(cin >> Q >> M && (Q||M))
    {
        memset(v,0,sizeof(v));

        for(int i=1; i<=Q; i++)
            for(int j=1; j<=Q; j++)
            {
                cin >> map[i][j];
                if(map[i][j]==-1)
                    map[i][j]=INF;
            }
        floyd();

        for(int i=1; i<=M; i++)
            cin >> p[i].id >> p[i].s >> p[i].d;

        for(int i=1; i<=M; i++)
            for(int j=1; j<=M; j++)
                if(p[j].s>=p[i].s+p[i].d+map[p[i].id][p[j].id])
                    v[i][j]=1;

        cout << M-solv() << endl;
    }
    return 0;
}
