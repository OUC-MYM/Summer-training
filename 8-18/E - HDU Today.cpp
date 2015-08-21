#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 160
#define INF 0x3f3f3f3f
using namespace std;

int N;
int cnt;

int vis[MAX];
int dis[MAX];
int len[MAX][MAX];
map<string,int> viss;

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
    while(cin >> N)
    {
        if(N==-1)
            break;

        memset(len,INF,sizeof(len));
        viss.clear();

        string temp1,temp2;
        int time;
        int flag=0;

        cin >> temp1 >> temp2;
        if(temp1==temp2)
            flag=1;
        viss[temp1]=1;
        viss[temp2]=2;

        cnt=2;
        while(N--)
        {
            cin >> temp1 >> temp2 >> time;
            if(!viss[temp1])
                viss[temp1]=++cnt;
            if(!viss[temp2])
                viss[temp2]=++cnt;
            if(time<len[viss[temp1]][viss[temp2]])
                len[viss[temp1]][viss[temp2]]=len[viss[temp2]][viss[temp1]]=time;
        }

        if(flag)
        {
            cout << 0 << endl;
            continue;
        }
        SPFA(1,2,cnt);
    }
    return 0;
}
