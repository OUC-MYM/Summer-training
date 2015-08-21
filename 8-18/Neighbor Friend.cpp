#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int N,M;
bool map[210][210];
bool link[210][210];

int main()
{
    while(cin >> N >> M)
    {
        memset(map,0,sizeof(map));
        memset(link,0,sizeof(link));

        while(M--)
        {
            int a,b;
            cin >> a >> b;
            map[a][b]=1;
        }

        for(int k=1; k<=N; k++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    if(map[i][k] && map[k][j])
                        map[i][j]=link[i][j]=1;

        int ans=0;
        for(int i=1; i<=N; i++)
            for(int j=i+1; j<=N; j++)
                if(link[i][j]||link[j][i])
                    ans++;

        cout << N*(N-1)/2-ans << endl;
        getchar();
    }
    return 0;
}
