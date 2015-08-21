#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 1010
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
int vis[MAX],dis[MAX];
int len[MAX][MAX];

void SPFA(int start,int end,int n)
{
    int u, v;
    memset(vis, 0, sizeof(vis));
    memset(dis, INF, sizeof(dis));

    dis[start]=0;

    queue<int> Q;
    Q.push(start);

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i=1; i<=n; i++)
        {
            v=i;
            if(len[u][v]+dis[u]<dis[v])
            {
                dis[v]=len[u][v]+dis[u];
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    if(dis[end]!=INF)
        cout << dis[end] << endl;
    else
        cout << -1 << endl;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> M >> N)
    {
        memset(len,INF,sizeof(len));
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(i==j)
                    len[i][j]=0;

        for(int i=1; i<=M; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(c<len[a][b])
                len[a][b]=len[b][a]=c;
        }
        SPFA(1,N,N);
    }
    return 0;
}
