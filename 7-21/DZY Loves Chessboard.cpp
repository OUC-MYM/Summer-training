#include <iostream>

using namespace std;

int n,m;
char map[110][110];
int ok;

/*
int dirX[]= {1,0,-1,0};
int dirY[]= {0,-1,0,1};


void dfs(int x,int y,char ch)
{
    int Ix,Iy;
    for(int i=0; i<4; i++)
    {
        Ix=x+dirX[i];
        Iy=y+dirY[i];
        if(map[Ix][Iy]!=0)
        {
            if(ch=='B')
            {
                map[Ix][Iy]='W';
                dfs(Ix,Iy,'W');
            }
            else
            {
                map[Ix][Iy]='B';
                dfs(Ix,Iy,'B');
            }
        }
    }
}
*/


int main()
{
    cin >> n >> m;

    char ch[]= {'B','W'};
    for(int j=1; j<=n; j++)
        for(int i=1; i<=m; i++)
        {
            map[i][j]=ch[(i+j)%2];
        }

    char temp;
    for(int j=1; j<=n; j++)
        for(int i=1; i<=m; i++)
        {
            cin >> temp;
            if(temp=='-')
                map[i][j]=temp;
        }

    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=m; i++)
        {
            cout << map[i][j];
        }
        if(j!=n)
            cout << endl;
    }

    return 0;
}
