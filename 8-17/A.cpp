#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 1<<30
#define MAXN 10010
using namespace std;


int N,M,sum,flag;
int pre[MAXN],in[MAXN];
vector<int>map[10005];
struct point
{
    int a;
    char ch;
    int b;
} p[MAXN];


int find (int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}


void topo(int n)
{
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(in[i]==0&&pre[i]==i)
            q.push(i);
    }
    while(!q.empty())
    {
        if(q.size()>1)
            flag=1;
        int v=q.front();
        q.pop();
        sum--;
        for(int i=0; i<map[v].size(); i++)
        {
            in[map[v][i]]--;
            if(!in[map[v][i]])
                q.push(map[v][i]);
        }
    }
}

bool unions(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return 0;
    pre[y]=x;
    return 1;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> M)
    {
        sum=N;
        for(int i=0; i<N; i++)
            pre[i]=i;
        memset(map,0,sizeof(map));
        memset(in,0,sizeof(in));

        for(int i=0; i<M; i++)
        {
            cin >> p[i].a >> p[i].ch >> p[i].b;
            if(p[i].ch=='=')
            {
                if(unions(p[i].a,p[i].b))
                    sum--;
            }
        }

        for(int i=0; i<M; i++)
        {
            if(p[i].ch=='=')
                continue;
            int x=find(p[i].a);
            int y=find(p[i].b);
            if(p[i].ch=='>')
            {
                map[x].push_back(y);
                in[y]++;
            }
            if(p[i].ch=='<')
            {
                map[y].push_back(x);
                in[x]++;
            }
        }
        flag=0;
        topo(N);

        if(sum>0)
            cout << "CONFLICT" << endl;
        else if(flag)
            cout << "UNCERTAIN" << endl;
        else
            cout << "OK" << endl;
    }
    return 0;
}
