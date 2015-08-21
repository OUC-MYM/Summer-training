#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
bool map[501][501];
int in[501];

priority_queue<int,vector<int>,greater<int> > q;
void topo(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    int cnt=1;
    while(!q.empty())
    {
        int v=q.top();
        q.pop();
        if(cnt!=n)
        {
            cout<<v<<" ";
            cnt++;
        }
        else
            cout<<v<<endl;
        for(int i=1; i<=n; i++)
        {
            if(map[v][i])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int n,m,i,j;
    while(cin>>n>>m)
    {
        memset(map,0,sizeof map);
        memset(in,0,sizeof in);
        while(m--)
        {
            cin>>i>>j;
            if(map[i][j])
                continue;
            map[i][j]=1;
            in[j]++;
        }
        topo(n);
    }
    return 0;
}
