#include <iostream>
#include <cstring>
#define MAX 110
#define inf 1<<29
using namespace std;

int N;
int map[110][110];

void prim()
{
    int i,j,d[MAX],vis[MAX],mi,v;
    for(i=1; i<=N; i++)
    {
        d[i]=map[1][i];
        vis[i]=0;
    }
    for(i=1; i<=N; i++)
    {
        mi=inf;
        for(j=1; j<=N; j++)
            if(!vis[j] && d[j]<mi)
            {
                mi=d[j];
                v=j;
            }
        vis[v]=1;
        for(j=1; j<=N; j++)
            if(!vis[j] && d[j]>map[v][j])
                d[j]=map[v][j];
    }
    for(d[0]=0,i=1; i<=N; i++)
        d[0]+=d[i];

    cout << d[0] <<endl;
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N && N)
    {
        memset(map,0,sizeof(map));
        for(int i=1; i<=N*(N-1)/2; i++)
        {
            int a,b;
            cin >> a >> b;
            cin >> map[a][b];
            map[b][a]=map[a][b];
        }
        prim();
    }
    return 0;
}
