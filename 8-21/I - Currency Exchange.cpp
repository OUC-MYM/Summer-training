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
#define MAX 250
using namespace std;

int N,M,S;
double V;

bool vis[MAX];
double d[MAX];
int head[MAX];
int cnt;

struct Edge
{
    int v;
    int next;
    double w;
    double miss;
} e[MAX];

void addEdge(int u, int v, double w,double miss)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    e[cnt].w = w;
    e[cnt].miss = miss;
    head[u] = cnt++;
}

int SPFA(int src)
{
    int u, v;
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    d[src] = V;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        if(d[src]>V)
            return 1;
        u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = e[i].next)
        {
            v = e[i].v;
            if(d[v] < (d[u]-e[i].miss) * e[i].w)
            {
                d[v] = (d[u]-e[i].miss) * e[i].w;
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
    while(cin >> N >> M >> S >> V)
    {
        memset(head, -1, sizeof(head));
        cnt=0;
        for(int i=1; i<=M; i++)
        {
            int a,b;
            double c,d,e,f;
            cin >> a >> b >> c >> d >> e >> f;
            addEdge(a,b,c,d);
            addEdge(b,a,e,f);
        }

        cout << (SPFA(S)?"YES":"NO") << endl;
    }
    return 0;
}
