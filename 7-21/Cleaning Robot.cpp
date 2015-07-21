#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

char map[30][30];
int vis[30][30][4];
int w,h;
int all;

int dirX[]= {-1,0,1,-1,1,-1,0,1};
int dirY[]= {1,1,1,0,0,-1,-1,-1};

bool inmap(int x,int y)
{
    if(x>w||y>h||x<=0||y<=0)
        return false;
    return true;
}

struct que
{
    int x;
    int y;
    int step;
    int sum;
    int dir;
};

int solv(int x,int y)
{
    queue <que> q;
    q.push(que {x,y,0,0,-1});
    while(!q.empty())
    {
         que temp=q.front();
         q.pop();

         vis[temp.x][temp.y][temp.dir]=1;

         if(map[temp.x][temp.y]=='*')
            temp.sum=temp.sum+1;

         if(temp.sum==all)
            return temp.step;

         int Ix,Iy;
         for(int i=0;i<8;i++)
         {
             Ix=temp.x+dirX[i];
             Iy=temp.y+dirY[i];
             if(inmap(Ix,Iy)&&!vis[Ix][Iy][i])
                q.push(que{Ix,Iy,temp.step+1,temp.sum,i});
         }
    }
    return -1;
}
int main()
{
    while(cin >> w >> h)
    {
        if(w==0&&h==0)
            break;
        all=0;
        int x,y;
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        for(int j=1; j<=h; j++)
            for(int i=1; i<=w; i++)
            {
                cin >> map[i][j];
                if(map[i][j]=='*')
                    all++;
                if(map[i][j]=='o')
                {
                    x=i;
                    y=j;
                }
            }
        cout << solv(x,y) << endl;
    }
    return 0;
}
