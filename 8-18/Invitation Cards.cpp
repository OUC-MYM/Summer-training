#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 1000100
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
int ans;
int vis[MAX],d[MAX];
int head[MAX];
int cnt;
int a[MAX],b[MAX],c[MAX];
struct Edge
{
    int v;
    int next;
    int w;
} e[MAX*3];

void addEdge(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    head[u] = cnt;
    cnt++;
}

void SPFA(int src)
{
    int u, v;
    memset(vis, 0, sizeof(vis));
    memset(d, INF, sizeof(d));
    d[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = e[i].next)
        {
            v = e[i].v;
            if(d[v] > d[u] + e[i].w)
            {
                d[v] = d[u] + e[i].w;
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        memset(head, -1, sizeof(head));
        cnt=ans=0;
        cin >> N >> M;
        for(int i=1; i<=M; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            addEdge(a[i],b[i],c[i]);
        }
        SPFA(1);
        for(int i=1; i<=N; i++)
            ans=ans+d[i];

        memset(head, -1, sizeof(head));
        for(int i=1; i<=M; i++)
            addEdge(b[i],a[i],c[i]);
        SPFA(1);
        for(int i=1; i<=N; i++)
            ans=ans+d[i];

        cout << ans << endl;
    }
    return 0;
}

