#include <iostream>
#include <queue>
#include <cstring>
#define INF 1<<29
#define MAX 100010
using namespace std;

struct Edge
{
    int v;
    int next;
}e[MAX*2];

int N,K,cnt,ans,tot;
int num[MAX],vis[MAX],head[MAX],d[MAX],army[MAX];

void addEdge(int u, int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
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
            if(d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
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
    while(cin >> N >> K)
    {
        cnt=ans=tot=0;
        for(int i=1; i<=N; i++)
        {
            cin >> num[i];
            if(num[i])
                tot++;
        }
        memset(head, -1, sizeof(head));
        for(int i = 0; i < K; i++)
            cin >> army[i];
        int u, v;
        for(int i = 0; i < N - 1; i++)
        {
            cin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }
        for(int i = 0; i < K; i++)
        {
            SPFA(army[i]);
            for(int j = 1; j <= N; j++)
            {
                if(!num[j])
                    continue;
                if(d[j] != INF)
                {
                    ans = ans + num[j];
                    num[j] = 0;
                    tot--;
                    if(tot == 0)
                        break;
                }
            }
            if(tot == 0)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
