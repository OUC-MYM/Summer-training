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
#define INF 1<<27
#define MAX 28
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
        mi=INF;
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
        memset(map,9999,sizeof(map));

        int cnt;
        char temp1,temp2;
        int num;
        map[0][0]=0;
        for(int i=1; i<N; i++)
        {
            map[i][i]=0;
            cin >> temp1;
            cin >> cnt;
            while(cnt--)
            {
                cin >> temp2 >> num;
                map[temp1-'A'+1][temp2-'A'+1]=map[temp2-'A'+1][temp1-'A'+1]=num;
            }
        }

        /*for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
                cout << map[i][j] << " ";
            cout << endl;
        }*/

        prim();
    }
    return 0;
}
