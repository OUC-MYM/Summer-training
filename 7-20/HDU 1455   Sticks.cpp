#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int n[70];
int all;
int MAXX;
int vis[70];
int ok=0;

void dfs(int sum, int ans, int cnt)
{
    if(ok)
        return;
    if(all/ans==cnt)
    {
        ok=1;
        return;
    }
    for(int i=T-1; i>=0; i--)
    {
        if(vis[i])
            continue;
        if(n[i]+sum<ans)
        {
            vis[i]=1;
            dfs(n[i]+sum,ans,cnt);
            vis[i]=0;
        }
        if(n[i]+sum==ans)
        {
            vis[i]=1;
            dfs(0,ans,cnt+1);
            vis[i]=0;
        }
        if(sum==0)
            return;
    }
    return;
}

int solv()
{
    int ans=0;
    for(ans=MAXX; ans<=all/2; ans++)
    {
        ok=0;
        memset(vis,0,sizeof(vis));
        if(all%ans==0)
            dfs(0,ans,0);
        if(ok)
            return ans;
    }
    return all;
}

int main()
{
    while(cin >> T && T)
    {
        all=0;
        MAXX=0;
        for(int i=0; i<T; i++)
        {
            cin >> n[i];
            all=all+n[i];

        }
        sort(n,n+T);
        MAXX=n[T-1];
        cout << solv() << endl;
    }
    return 0;
}
