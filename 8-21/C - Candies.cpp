#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#define MAX 30100
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
int vis[MAX];
int d[MAX];
int head[MAX];
int cnt;
int w[MAX];
struct Edge
{
    int v;
    int next;
    int w;
} e[150010];

void addEdge(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    head[u] = cnt++;
}

void SPFA(int src)
{
    int u, v;
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=N; i++)
        d[i]=INF;
    d[src] = 0;
    stack<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        u = Q.top();
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
    while(~scanf("%d%d",&N,&M))
    {
        memset(head, -1, sizeof(head));
        cnt=0;
        for(int i=1; i<=M; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
        }
        SPFA(1);
        printf("%d\n",d[N]);
    }
    return 0;
}
