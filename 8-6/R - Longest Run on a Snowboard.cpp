#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int map[110][110];
int m,n;
int dirX[4]= {0,0,-1,1};
int dirY[4]= {1,-1,0,0};
int length[110][110];

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

bool inmap(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n)
        return false;
    return true;
}

int dfs(int x, int y)
{
    int Ix, Iy;
    if(length[x][y]==0)
    {
        for(int i=0; i<4; i++)
        {
            Ix = x + dirX[i];
            Iy = y + dirY[i];
            if(inmap(Ix, Iy) && map[Ix][Iy]<map[x][y])
            {
                int temp = dfs(Ix,Iy);
                if(length[x][y] <= temp)
                    length[x][y] = temp;
            }
        }
    }
    return length[x][y]+1;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(length,0,sizeof(length));

        string temp;
        cin >> temp;

        cin >> m >> n;
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    scanf("%d",&map[i][j]);
                }
            }

            int mostLength=-1;

            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    mostLength=max(mostLength,dfs(i, j));
                }
            }
            cout << temp << ": ";
            printf("%d\n",mostLength);
        }
    }
    return 0;
}
