#include <iostream>
#include <cstring>
using namespace std;

int n,k;
char map[10][10];
int vis[10];
unsigned long long ans;

void dfs(int x,int t)
{
    if(n-x<k-t)
       return;

    if(t==k)
    {
        ans++;
        return;
    }

    for(int i=0; i<n; i++)
        if(map[x+1][i]=='#')
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(x+1,t+1);
                vis[i]=0;
            }
        }
        dfs(x+1,t);
}

int main()
{
    while(cin >> n >> k)
    {
        if(n==-1&&k==-1)
            break;

        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        ans=0;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> map[i][j];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[i][j]=='#')
                {
                    vis[j]=1;
                    dfs(i,1);
                    vis[j]=0;
                }
        cout << ans << endl;
    }
    return 0;
}
