#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int map[110][110];
int m,n,k;
int dirX[4]= {0,0,-1,1};
int dirY[4]= {1,-1,0,0};
int sum[110][110];

bool inmap(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n)
        return false;
    return true;
}

int dfs(int x, int y)
{
    int Ix, Iy;
    if(sum[x][y]==0)
    {
        for(int j=1; j<=k; j++)
            for(int i=0; i<4; i++)
            {
                Ix = x + j*dirX[i];
                Iy = y + j*dirY[i];
                if(inmap(Ix, Iy) && map[Ix][Iy]>map[x][y])
                {
                    int temp = dfs(Ix,Iy);
                    if(sum[x][y] <= temp)
                        sum[x][y] = temp;
                }
            }
        sum[x][y]=sum[x][y]+map[x][y];
    }
    return sum[x][y];
}

int main()
{
    while(~scanf("%d%d",&m,&k))
    {
        memset(sum,0,sizeof(sum));
        if(m==-1&&k==-1)
            break;
        n=m;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
