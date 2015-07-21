#include <iostream>
#include<cstring>
#include <queue>
using namespace std;

char map[85][85];
int vis[85][85][4];
int h,w;
int dirX[]= {0,0,1,-1};
int dirY[]= {1,-1,0,0};

bool endd(int x,int y)
{
    if(x==w-1||y==h-1||x==0||y==0)
        return true;
    return false;
}

struct que
{
    int x;
    int y;
    int step;
    int dir;
};

int bfs(int x,int y)
{
    queue <que> q;
    if(endd(x,y))
        return 0;
    for(int i=0; i<4; i++)
        if(map[y+dirY[i]][x+dirX[i]]=='.')
            q.push(que {x+dirX[i],y+dirY[i],1,i});
    while(!q.empty())
    {
        que temp=q.front();
        q.pop();
        if(endd(temp.x,temp.y))
            return temp.step;
        if(!vis[temp.y][temp.x][temp.dir])
        {
            vis[temp.y][temp.x][temp.dir]=1;
            int go=0;
            if(temp.dir==0||temp.dir==1)
            {
                for(int i=2; i<4; i++)
                    if(map[temp.y+dirY[i]][temp.x+dirX[i]]=='.')
                    {
                        go=1;
                        q.push(que {temp.x+dirX[i],temp.y+dirY[i],temp.step+1,i});
                    }
                if(!go&&map[temp.y+dirY[temp.dir]][temp.x+dirX[temp.dir]]=='.')
                    q.push(que {temp.x+dirX[temp.dir],temp.y+dirY[temp.dir],temp.step+1,temp.dir});
            }
            if(temp.dir==2||temp.dir==3)
            {
                for(int i=0; i<=1; i++)
                    if(map[temp.y+dirY[i]][temp.x+dirX[i]]=='.')
                    {
                        go=1;
                        q.push(que {temp.x+dirX[i],temp.y+dirY[i],temp.step+1,i});
                    }
                if(!go&&map[temp.y+dirY[temp.dir]][temp.x+dirX[temp.dir]]=='.')
                    q.push(que {temp.x+dirX[temp.dir],temp.y+dirY[temp.dir],temp.step+1,temp.dir});
            }
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
                if(map[i][j]=='@')
                {
                    y=i;
                    x=j;
                }
            }
        cout << bfs(x,y) << endl;
    }
}

/*
9 13
#############
.@..........#
#####.#.#.#.#
#...........#
#.#.#.#.#.#.#
#.#.......#.#
#.#.#.#.#.#.#
#...........#
#####.#######

9 13
#############
#@..........#
#####.#.#.#.#
#...........#
#.#.#.#.#.#.#
#.#.......#.#
#.#.#.#.#.#.#
#...........#
#####.#######

9 13
#############
#@..........#
#####.#.#.#.#
#............
#.#.#.#.#.#..
#.#.......#.#
#.#.#.#.#.#.#
#...........#
#####.#######
*/
