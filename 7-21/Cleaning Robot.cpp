#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

char map[30][30];
int vis[30][30];
int dis[30][30];
int w,h;
int cnt;
int ok;
int ans;

int dirX[]= {-1,0,1,0};
int dirY[]= {0,1,0,-1};

struct point
{
    int x;
    int y;
} p[15];

bool inmap(int x,int y)
{
    if(x>h||y>w||x<=0||y<=0)
        return false;
    return true;
}

struct que
{
    int x;
    int y;
    int step;
};

int bfs(int x,int y,int s,int e)
{
    memset(vis,0,sizeof(vis));

    queue <que> q;
    q.push(que {x,y,0});
    que temp;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp.x==s&&temp.y==e)
            return temp.step;

        int Ix,Iy;
        for(int i=0; i<4; i++)
        {
            Ix=temp.x+dirX[i];
            Iy=temp.y+dirY[i];
            if(inmap(Ix,Iy)&&map[Ix][Iy]!='x'&&!vis[Ix][Iy])
            {
                vis[Ix][Iy]=1;
                q.push(que {Ix,Iy,temp.step+1});
            }

        }
    }

    return -1;
}


int viss[15];
void dfs(int k,int n,int sum)
{
    if(sum>ans)
        return;

    if(n==cnt+1)
    {
        ans=min(ans,sum);
        return;
    }
    for(int i=1; i<=cnt; i++)
        if(!viss[i])
        {
            viss[i]=1;
            dfs(i,n+1,sum+dis[k][i]);
            viss[i]=0;
        }
}

int main()
{
    while(cin >> w >> h && (w||h))
    {
        cnt=0;
        ok=1;
        ans=999999999;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
            {
                cin >> map[i][j];
                if(map[i][j]=='o')
                {
                    p[0].x=i;
                    p[0].y=j;
                }
                if(map[i][j]=='*')
                {
                    p[++cnt].x=i;
                    p[cnt].y=j;
                }
            }
        //cout <<cnt << endl;
        for(int i=0; i<=cnt; i++)
        {
            if(!ok)
                break;
            for(int j=i+1; j<=cnt; j++)
            {
                dis[i][j]=dis[j][i]=bfs(p[i].x,p[i].y,p[j].x,p[j].y);
                //cout << dis[i][j] << endl;
                if(dis[i][j]==-1)
                {
                    ok=0;
                    break;
                }
            }
        }

        if(!ok)
        {
            cout << "-1" << endl;
            continue;
        }


            memset(viss,0,sizeof(viss));
            viss[0];
            dfs(0,1,0);

        cout << ans << endl;
    }
    return 0;
}
