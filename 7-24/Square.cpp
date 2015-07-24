#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int n[70];
int all;
int MAXX;
int ans;
int vis[70];
int ok;

bool cmp(int a,int b)
{
    return a>b;
}

void dfs(int sum, int pos, int cnt)
{
    if(ok)
        return;
    if(all/ans==cnt)
    {
        ok=1;
        return;
    }
    for(int i=pos+1; i<T; i++)
    {
        if(vis[i])
            continue;
        if(n[i]+sum<ans)
        {
            vis[i]=1;
            dfs(n[i]+sum,i,cnt);
            vis[i]=0;
        }
        if(n[i]+sum==ans)
        {
            vis[i]=1;
            dfs(0,-1,cnt+1);
            vis[i]=0;
        }
        if(sum==0)
            return;
    }
    return;
}

int solv()
{
    if(all%4==0)
    {
        ans=all/4;
        ok=0;
        memset(vis,0,sizeof(vis));
        if(all%ans==0)
            dfs(0,-1,0);
        if(ok)
            return ans;
    }
    return all;
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {

        cin >> T;
        all=0;
        for(int i=0; i<T; i++)
        {
            cin >> n[i];
            all=all+n[i];
        }
        sort(n,n+T,cmp);
        MAXX=n[0];

        int temp=solv();

        if(temp==all)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
