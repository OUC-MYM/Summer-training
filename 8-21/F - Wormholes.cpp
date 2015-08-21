#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 0x3f3f3f3f
#define MAX 5500
using namespace std;

int N,M,W;

int vis[MAX];
int d[MAX];
int head[MAX];
int tot[MAX];
int cnt;
int w[MAX];
struct Edge
{
    int v;
    int next;
    int w;
} e[MAX];

void addEdge(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    head[u] = cnt++;
}

int SPFA(int src)
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
        tot[u]++;
        if(tot[u]>M)
            return 1;
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
    return 0;
}


int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> M >> W;
        memset(head, -1, sizeof(head));
        memset(tot, 0, sizeof(tot));
        cnt=0;
        for(int i=1; i<=M; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        for(int i=1; i<=W; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            addEdge(a,b,-c);
        }

        cout << (SPFA(1)?"YES":"NO") << endl;
    }
    return 0;
}
