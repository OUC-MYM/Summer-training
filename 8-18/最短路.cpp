#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX  9999999
using namespace std;

int w[250][250];

int main()
{
    int  N,M;
    while(cin >> N >> M && (N||M))
    {

        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=N; j++)
            {
                w[i][j]=MAX;
                if(i==j)
                    w[i][j]=0;
            }
        }

        for(int j=0; j<M; j++)
        {
            int x,y,d;
            scanf("%d %d %d",&x,&y,&d);
            if(w[x][y]>d)
                w[x][y]=w[y][x]=d;
        }

        for(int k=1; k<=N; k++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                {
                    if(w[i][j]>w[i][k]+w[k][j])
                        w[i][j]=w[i][k]+w[k][j];
                }

        if(w[1][N]==MAX)
            printf("-1\n");
        else
            printf("%d\n",w[1][N]);
    }
    return 0;
}
