#include <iostream>
#include<cstring>
#include <queue>
using namespace std;

int map[10][10];
int vis[10][10][8];
int h,w;
int ex,ey;
int dirX[]= {0,0,1,-1};
int dirY[]= {1,-1,0,0};

bool check(int x,int y)
{
    if(x<0||y<0||x>=h||y>=w)
        return false;
    if(map[x][y]==0)
        return false;
    return true;
}

struct que
{
    int x;
    int y;
    int step;
    int time;
};

int bfs(int x,int y)
{
    queue <que> q;

    q.push(que {x,y,0,6});
    que temp;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

       // cout << temp.x << temp.y << temp.time << endl;

        if(temp.x==ex&&temp.y==ey&&temp.time>0)
            return temp.step;

        if(temp.time==0)
            continue;

        vis[temp.x][temp.y][temp.time]=1;

        int Ix,Iy;
        for(int i=0; i<4; i++)
        {
            Ix=temp.x+dirX[i];
            Iy=temp.y+dirY[i];
            if(check(Ix,Iy)&&map[Ix][Iy]==4&&!vis[Ix][Iy][6])
            {
                if(temp.time>1)
                    q.push(que {Ix,Iy,temp.step+1,6});
            }
            else if(check(Ix,Iy)&&!vis[Ix][Iy][temp.time])
                q.push(que {Ix,Iy,temp.step+1,temp.time-1});
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        int x,y;
        cin >> h >> w;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                cin >> map[i][j];
                if(map[i][j]==2)
                {
                    x=i;
                    y=j;
                }
                if(map[i][j]==3)
                {
                    ex=i;
                    ey=j;
                }
            }
        cout << bfs(x,y) << endl;
    }
}
