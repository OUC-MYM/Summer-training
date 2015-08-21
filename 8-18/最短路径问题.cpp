#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX 1010
using namespace std;

int n,m,a,b,d,p;
int vis[MAX];
int dis[MAX],pay[MAX];
int len[MAX][MAX],cost[MAX][MAX];

void SPFA(int start,int end,int n)
{
    int u, v;
    memset(vis, 0, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    memset(pay, INF, sizeof(pay));

    dis[start]=pay[start]=0;

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
                pay[v]=cost[u][v]+pay[u];
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
        if(len[u][v]+dis[u]==dis[v]&&pay[v]>cost[u][v]+pay[u])
           pay[v]=cost[u][v]+pay[u];
    }
    cout << dis[end] << " " << pay[end] << endl;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> n >> m && (n||m))
    {
        memset(len,INF,sizeof(len));
        memset(cost,INF,sizeof(cost));

        while(m--)
        {
            cin >> a >> b >> d >> p;
            if(d<len[a][b])
            {
                len[a][b]=len[b][a]=d;
                cost[a][b]=cost[b][a]=p;
            }
        }

        int s,e;
        cin >> s >> e;
        SPFA(s,e,n);
    }
    return 0;
}
