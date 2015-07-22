#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char map[50][50];
int vis[50][50];
int w,h;
int startX,startY,stopX,stopY;
int dirX[]= {0,1,0,-1};
int dirY[]= {-1,0,1,0};

struct que
{
    int x;
    int y;
    int step;
};

bool inmap(int x,int y)
{
    if(x<0||y<0||x>=w||y>=h)
        return false;
    return true;
}

int bfs(int x,int y)
{
    queue <que> q;

    q.push(que {x,y,1});

    while(!q.empty())
    {
        que temp=q.front();
        q.pop();

        int Ix,Iy;
        for(int i=0; i<4; i++)
        {
            Ix=temp.x+dirX[i];
            Iy=temp.y+dirY[i];

            if(map[Iy][Ix]=='E')
                return temp.step+1;

            if(inmap(Ix,Iy)&&!vis[Ix][Iy]&&map[Iy][Ix]=='.')
            {
                vis[Ix][Iy]=1;
                q.push(que {Ix,Iy,temp.step+1});
            }
        }
    }
    return -1;
}

int dfsL(int x,int y,int dir)
{
    if(map[y+dirY[(4+dir-1)%4]][x+dirX[(4+dir-1)%4]]=='E')
        return 2;
    if(inmap(x+dirX[(4+dir-1)%4],y+dirY[(4+dir-1)%4])&&map[y+dirY[(4+dir-1)%4]][x+dirX[(4+dir-1)%4]]=='.')
        return dfsL(x+dirX[(4+dir-1)%4],y+dirY[(4+dir-1)%4],(4+dir-1)%4)+1;

    if(map[y+dirY[dir]][x+dirX[dir]]=='E')
        return 2;
    if(inmap(x+dirX[dir],y+dirY[dir])&&map[y+dirY[dir]][x+dirX[dir]]=='.')
        return dfsL(x+dirX[dir],y+dirY[dir],dir)+1;

    if(map[y+dirY[(4+dir+1)%4]][x+dirX[(4+dir+1)%4]]=='E')
        return 2;
    if(inmap(x+dirX[(4+dir+1)%4],y+dirY[(4+dir+1)%4])&&map[y+dirY[(4+dir+1)%4]][x+dirX[(4+dir+1)%4]]=='.')
        return dfsL(x+dirX[(4+dir+1)%4],y+dirY[(4+dir+1)%4],(4+dir+1)%4)+1;

    return dfsL(x+dirX[(4+dir+2)%4],y+dirY[(4+dir+2)%4],(4+dir+2)%4)+1;
}

int dfsR(int x,int y,int dir)
{
    if(map[y+dirY[(4+dir+1)%4]][x+dirX[(4+dir+1)%4]]=='E')
        return 2;
    if(inmap(x+dirX[(4+dir+1)%4],y+dirY[(4+dir+1)%4])&&map[y+dirY[(4+dir+1)%4]][x+dirX[(4+dir+1)%4]]=='.')
        return dfsR(x+dirX[(4+dir+1)%4],y+dirY[(4+dir+1)%4],(4+dir+1)%4)+1;

    if(map[y+dirY[dir]][x+dirX[dir]]=='E')
        return 2;
    if(inmap(x+dirX[dir],y+dirY[dir])&&map[y+dirY[dir]][x+dirX[dir]]=='.')
        return dfsR(x+dirX[dir],y+dirY[dir],dir)+1;

    if(map[y+dirY[(4+dir-1)%4]][x+dirX[(4+dir-1)%4]]=='E')
        return 2;
    if(inmap(x+dirX[(4+dir-1)%4],y+dirY[(4+dir-1)%4])&&map[y+dirY[(4+dir-1)%4]][x+dirX[(4+dir-1)%4]]=='.')
        return dfsR(x+dirX[(4+dir-1)%4],y+dirY[(4+dir-1)%4],(4+dir-1)%4)+1;

    return dfsR(x+dirX[(4+dir+2)%4],y+dirY[(4+dir+2)%4],(4+dir+2)%4)+1;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(map,0,sizeof(map));
        cin >> w >> h;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                cin >> map[i][j];
                if(map[i][j]=='S')
                {
                    startX=j;
                    startY=i;
                }
                if(map[i][j]=='E')
                {
                    stopX=j;
                    stopY=i;
                }
            }


        int dir;
        for(int i=0; i<4; i++)
        {
            int Ix=startX+dirX[i];
            int Iy=startY+dirY[i];
            if(inmap(Ix,Iy)&&map[Iy][Ix]=='.')
            {
                dir=i;
                break;
            }
        }

        memset(vis,0,sizeof(vis));
        cout << dfsL(startX,startY,dir) << " ";

        memset(vis,0,sizeof(vis));
        cout << dfsR(startX,startY,dir) << " ";

        memset(vis,0,sizeof(vis));
        cout << bfs(startX,startY) << endl;
    }
    return 0;
}
