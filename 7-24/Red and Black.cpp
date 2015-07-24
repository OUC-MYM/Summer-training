#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w,h;
char map[25][25];
int vis[25][25];
int dirX[]= {1,0,-1,0};
int dirY[]= {0,1,0,-1};
int s,e;
int ans;

bool inmap(int x,int y)
{
    if(x<0||y<0||x>=h||y==w)
        return false;
    return true;
}

struct que
{
    int x;
    int y;
};

void bfs(int x,int y)
{
     queue <que> q;
     q.push(que{x,y});
     que temp;
     while(!q.empty())
     {
         temp=q.front();
         q.pop();

         int Ix,Iy;
         for(int i=0;i<4;i++)
         {
             Ix=temp.x+dirX[i];
             Iy=temp.y+dirY[i];
             if(inmap(Ix,Iy)&&map[Ix][Iy]=='.')
             {
                 map[Ix][Iy]='#';
                 ans++;
                 q.push(que{Ix,Iy});
             }
         }
     }
}

int main()
{
    while(cin >> w >> h && (w||h))
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        ans=1;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                cin >> map[i][j];
                if(map[i][j]=='@')
                {
                    s=i;
                    e=j;
                }
            }
        bfs(s,e);
        cout << ans << endl;
    }
}
