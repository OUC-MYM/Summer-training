#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char map[50][50];
int mapnum[50][50];
int m;

void add(int i,int j)
{
    if(i-2>0&&map[i-2][j]!='H')
    {
        map[i-1][j]='|';
        map[i-2][j]='H';
    }
    else
    {
        map[i+1][j]='|';
        map[i+2][j]='H';
    }
    if(j-2>0&&map[i][j-2]!='H')
    {
        map[i][j-1]='-';
        map[i][j-2]='H';
    }
    else
    {
        map[i][j+1]='-';
        map[i][j+2]='H';
    }
}

int main()
{
    int N=0;

    while(cin >> m && m)
    {
        N++;
        memset(map,' ',sizeof(map));

        for(int i=1; i<4*m-1; i+=4)
            for(int j=3; j<4*m+3; j+=4)
            {
                map[i][j]='O';
                cin >> mapnum[i][j];
                if(mapnum[i][j]==1)
                {
                    map[i][j-1]=map[i][j+1]='-';
                    map[i][j-2]=map[i][j+2]='H';
                }
                else if(mapnum[i][j]==-1)
                {
                    map[i-1][j]=map[i+1][j]='|';
                    map[i-2][j]=map[i+2][j]='H';
                }
                else add(i,j);
            }

        for(int i=0; i<4*m+3; i++)
            map[0][i]='*';
        for(int i=0; i<4*m+3; i++)
            map[4*m-2][i]='*';
        for(int i=0; i<4*m-1; i++)
            map[i][0]='*';
        for(int i=0; i<4*m-1; i++)
            map[i][4*m+2]='*';

        cout << "Case " << N << ":" << endl << endl;

        for(int i=0; i<4*m-1; i++)
        {
            for(int j=0; j<4*m+3; j++)
                cout << map[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
