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
#define INF 1<<30
#define MAXN 1500
using namespace std;

int N,M,K;
int N1,N2;
bool v[MAXN][MAXN];
bool vis[MAXN];
int father[MAXN];
bool map[MAXN][MAXN];

bool link(int n)
{
    for(int i=1; i<=N2; i++)
        if(v[n][i]&&!vis[i])
        {
            vis[i]=1;
            if(father[i]==0||link(father[i]))
            {
                father[i]=n;
                return true;
            }
        }
    return false;
}

int solv()
{
    N1=N2=(N+1)*(M+1);
    int cnt=0;
    memset(father,0,sizeof(father));
    for(int i=1; i<=N1; i++)
    {
        memset(vis,0,sizeof(vis));
        if(link(i))
            cnt++;
    }
    return cnt;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> M >> K)
    {
        memset(map,0,sizeof(map));
        memset(v,0,sizeof(v));

        for(int i=0; i<K; i++)
        {
            int a,b;
            cin >> a >> b;
            map[b][a]=1;
        }

        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                if(!map[i][j])
                {
                    if(!map[i][j+1]&&j+1<=M)
                        v[i*M+j][i*M+j+1]=1;
                    if(!map[i+1][j]&&i+1<=N)
                        v[i*M+j][(i+1)*M+j]=1;
                    if(!map[i][j-1]&&j-1>=1)
                        v[i*M+j][i*M+j-1]=1;
                    if(!map[i-1][j]&&i-1>=1)
                        v[i*M+j][(i-1)*M+j]=1;
                }
        int ans=solv();
        cout << ((ans==N*M-K)? ("YES") : ("NO")) << endl;
    }
    return 0;
}

/*
4 3 2
2 1
3 3
4 4 2
4 1
2 4
4 4 3
4 1
1 2
2 4
*/
