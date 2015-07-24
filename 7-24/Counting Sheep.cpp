#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w,h;
char map[110][110];
int dirX[]= {1,0,-1,0};
int dirY[]= {0,1,0,-1};
int ans;

bool inmap(int x,int y)
{
    if(x<0||y<0||x>=h||y==w)
        return false;
    return true;
}

void dfs(int x,int y)
{
    //cout << x << " " << y <<endl;
    int Ix,Iy;
    for(int i=0; i<4; i++)
    {
        Ix=x+dirX[i];
        Iy=y+dirY[i];
        if(inmap(Ix,Iy)&&map[Ix][Iy]=='#')
            {
                map[Ix][Iy]='.';
                dfs(Ix,Iy);
            }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> h >> w;
        memset(map,0,sizeof(map));
        ans=0;

        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> map[i][j];

        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                if(map[i][j]=='#')
                {
                    map[i][j]='.';
                    //cout <<i << " " << j <<endl;
                    ans++;
                    dfs(i,j);
                }
            }

        cout << ans << endl;
    }
    return 0;
}
