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
#define MAXN 510
using namespace std;

int ans[MAXN];
int map[MAXN][MAXN];
int n,m;

int tuoposort(int n,int mat[][MAXN],int ret[])
{
    int d[MAXN],i,j,k;

    for(i=0; i<n; i++)
        for(d[i]=j=0; j<n; d[i]+=mat[j++][i])
            ;

    for(k=0; k<n; ret[k++]=i)
    {
        for(i=0; d[i]&&i<n; i++)
            ;
        if(i==n)
            return 0;
        for(d[i]=-1,j=0; j<n; j++)
            d[j]-=mat[i][j];
    }
    return 1;
}



int main()
{
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            map[a-1][b-1]=1;
        }

        tuoposort(n,map,ans);

        for(int i=0; i<n; i++)
        {
            if(i)
                cout << " ";
            cout << ans[i]+1;
        }
        cout << endl;
    }
    return 0;
}
