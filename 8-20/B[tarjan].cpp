#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<stack>
using namespace std;

const int maxn=10002;
const int maxm=100002;
int dfn[maxn],low[maxn],n,m,indx,cnt,inStack[maxn],f[maxn][102];
stack<int>s;

void Tarjan(int u)
{
    dfn[u]=low[u]=indx++;
    inStack[u]=1;
    s.push(u);
    for(int i=f[u][0]; i>=1; i--)
    {
        int v=f[u][i];
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        int v;
        do
        {
            v=s.top();
            s.pop();
            inStack[v]=0;
        }
        while(u!=v);
        cnt++;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int i,j,k,a,b;
    while(cin >> n >> m && (n||m))
    {
        memset(dfn,0,sizeof(dfn));
        memset(inStack,0,sizeof(inStack));
        memset(low,0,sizeof(low));
        memset(f,0,sizeof(f));
        indx=cnt=0;
        for(i=1; i<=m; i++)
        {
            cin >> a >> b;
            f[a][++f[a][0]]=b;
        }
        for(i=1; i<=n; i++)
        {
            if(!dfn[i])
                Tarjan(i);
        }
        if(cnt==1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
