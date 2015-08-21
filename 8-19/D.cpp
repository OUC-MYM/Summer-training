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
#define INF 1<<30
#define MAXN 510
using namespace std;

int N,K;
int N1,N2;
bool v[MAXN][MAXN];
bool vis[MAXN];
int father[MAXN];

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
    N1=N2=N;
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
   while(cin >> N >> K)
   {
       memset(v,0,sizeof(v));
       while(K--)
       {
           int a,b;
           cin >> a >> b;
           v[a][b]=1;
       }
       cout << solv() << endl;
   }
   return 0;
}
