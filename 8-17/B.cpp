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
#define MAXN 2010
using namespace std;


int N;
int map[MAXN][MAXN];

int tuoposort(int n,int mat[][MAXN])
{
    int d[MAXN],i,j,k;

    for(i=0; i<n; i++)
        for(d[i]=j=0; j<n; d[i]+=mat[j++][i])
            ;

    for(k=0; k<n; k++)
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
    cin.sync_with_stdio(false);
    int T;
    int cnt=0;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                {
                    char temp;
                    cin >> temp;
                    map[i][j]=temp-'0';
                }

        if(tuoposort(N,map))
            cout << "Case #" << ++cnt << ": " << "No" << endl;
        else
            cout << "Case #" << ++cnt << ": " << "Yes" << endl;
    }
    return 0;
}
