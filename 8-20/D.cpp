#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 0x3f3f3f3f
#define MAXN 310
using namespace std;

int N;
int map[MAXN][MAXN];

bool visx[MAXN],visy[MAXN];
int link[MAXN];
int lx[MAXN],ly[MAXN],s[MAXN];

bool dfs(int x)
{
    visx[x]=1;
    for(int y=1; y<=N;y++)
    {
        if(visy[y])
            continue;
        int temp=lx[x]+ly[y]-map[x][y];
        if(temp==0)
        {
            visy[y]=1;
            if(link[y]==0||dfs(link[y]))
            {
                link[y]=x;
                return true;
            }
        }
        else
            s[y]=min(s[y],temp);
    }
    return false;
}

int KM()
{
    memset(link,0,sizeof(link));
    memset(ly,0,sizeof(ly));
    for(int i=1; i<=N; i++)
    {
        lx[i]=0;
        for(int j=1; j<=N; j++)
            lx[i]=max(lx[i],map[i][j]);
    }

    for(int x=1; x<=N; x++)
    {
        memset(s,INF,sizeof(s));
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(dfs(x))
                break;
            int d=INF;
            for(int i=1; i<=N; i++)
                if(!visy[i])
                    d=min(d,s[i]);
            for(int i=1; i<=N; i++)
                if(visx[i])
                    lx[i]=lx[i]-d;
            for(int i=1; i<=N; i++)
            {
                if(visy[i])
                    ly[i]=ly[i]+d;
                else
                    s[i]=s[i]-d;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=N; i++)
        if(link[i])
            ans=ans+map[link[i]][i];
    return ans;
}

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N)
    {
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                cin >> map[i][j];
        cout << KM() << endl;
    }
    return 0;
}
