#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[60][60];
int vis[60][60][4];
int startX,startY,stopX,stopY;

struct que
{
    int x;
    int y;
    int dir;
    int step;
};

int dirX[]= {-1,0,1,0};
int dirY[]= {0,1,0,-1};

int M,N;

bool inmap(int x,int y)
{
    if(x<1||y<1||x>=M||y>=N)
        return false;
    if (map[x][y] || map[x+1][y] || map[x][y+1] || map[x+1][y+1])
        return false;
    return true;
}

int bfs(int x,int y,int direction)
{
    if (startX == stopX && startY == stopY)
        return 0;
    if (!inmap(stopX, stopY))
        return -1;

    queue <que> q;

    q.push(que {x,y,direction,0});
    vis[x][y][direction]=1;

    while(!q.empty())
    {
        que temp=q.front();
        q.pop();

       // cout << temp.x << temp.y << temp.step  << temp.dir << endl;

        if(temp.x==stopX&&temp.y==stopY)
            return temp.step;

        int Ix,Iy;

        for(int i=0; i<4; i++)
        {
            if((4+i-temp.dir)%4!=2)
            {
                if(i==temp.dir)
                    for(int k=1; k<=3; k++)
                    {
                        Ix=temp.x+k*dirX[i];
                        Iy=temp.y+k*dirY[i];
                        if(inmap(Ix,Iy)&&!vis[Ix][Iy][temp.dir])
                        {
                            vis[Ix][Iy][temp.dir]=1;
                            q.push(que {Ix,Iy,temp.dir,temp.step+1});
                            //cout << Ix << Iy << temp.step+1 << endl;
                        }
                        if(!inmap(Ix,Iy))
                            break;
                    }
                if(i!=temp.dir)
                {
                    if(!vis[temp.x][temp.y][i])
                    {
                        vis[temp.x][temp.y][i]=1;
                        q.push(que {temp.x,temp.y,i,temp.step+1});
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    while(cin >> M >> N && (N||M))
    {
        memset(vis,0,sizeof(vis));

        for(int i=1; i<=M; i++)
            for(int j=1; j<=N; j++)
                cin >> map[i][j];

        cin >> startX >> startY >> stopX >> stopY;

        string temp;
        int direction;
        cin >> temp;

        if(temp=="south")
            direction=2;

        if(temp=="east")
            direction=1;

        if(temp=="north")
            direction=0;

        if(temp=="west")
            direction=3;

        cout << bfs(startX,startY,direction) << endl;
    }
}
