#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAX 1000100
#define INF 0x3f3f3f3f
using namespace std;

int N,M,X;
int ans[MAX],ans_T;
int vis[MAX],d[MAX];
int head1[MAX],head2[MAX];
int cnt1,cnt2;
struct Edge
{
    int v;
    int next;
    int w;
} e1[MAX],e2[MAX];

void addEdge(int u, int v, int w)
{
    e1[cnt1].v = v;
    e1[cnt1].next = head1[u];
    e1[cnt1].w = w;
    head1[u] = cnt1++;

    e2[cnt2].v = u;
    e2[cnt2].next = head2[v];
    e2[cnt2].w = w;
    head2[v] = cnt2++;
}

void SPFA(int src,Edge e[],int head[])
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
    while(~scanf("%d%d%d",&N,&M,&X))
    {
        memset(head1, -1, sizeof(head1));
        memset(head2, -1, sizeof(head2));
        memset(ans, 0, sizeof(ans));
        cnt1=cnt2=0;


        for(int i=1; i<=M; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
        }
        SPFA(X,e1,head1);
        for(int i=1; i<=N; i++)
            ans[i]=ans[i]+d[i];


        SPFA(X,e2,head2);
        for(int i=1; i<=N; i++)
            ans[i]=ans[i]+d[i];

        ans_T=0;
        for(int i=1; i<=N; i++)
            ans_T=max(ans_T,ans[i]);

        printf("%d\n",ans_T);
    }
    return 0;
}
