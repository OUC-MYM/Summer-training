#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 50100
#define INF 9999999999999999
using namespace std;

int N,M;
long long ans;
int vis[MAX];
long long d[MAX];
int head[MAX];
int cnt;
int w[MAX];
struct Edge
{
    int v;
    int next;
    long long w;
} e[MAX<<2];

void addEdge(int u, int v, long long w)
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
    //cin.sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(head, -1, sizeof(head));
        cnt=ans=0;

        scanf("%d%d",&N,&M);
        for(int i=1; i<=N; i++)
            scanf("%d",&w[i]);
        for(int i=1; i<=M; i++)
        {
            long long a,b,c;
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        SPFA(1);
        int flag=0;
        for(int i=1; i<=N; i++)
            {
                if(d[i]==INF)
                {
                    flag=1;
                    break;
                }
                ans=ans+w[i]*d[i];
            }

        if(flag)
            printf("No Answer\n");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}
