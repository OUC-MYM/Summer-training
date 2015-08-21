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
#define MAXN 1000
using namespace std;

int N,M;
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
    N1=N;
    N2=M;
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
    while(cin >> N)
    {
       memset(v,0,sizeof(v));
       M=0;
       for(int i=1;i<=N;i++)
       {
           int t,a,b;
           cin >> t;
           while(t--)
           {
               cin >> a >> b;
               v[i][a*13+b]=1;
               M=max(M,a*13+b);
           }
       }
       cout << solv() << endl;
    }
    return 0;
}
