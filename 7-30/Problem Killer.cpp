#include <iostream>
#include <queue>
using namespace std;

char map[1010][1010];
int w,h;
int ans[2000];

struct point
{
    int x;
    int y;
};

queue <point> q;
queue <point> old;

bool inmap(int x,int y)
{
    if(x<=0||y<=0||x>h||y>w)
        return false;
    return true;
}

void bfs()
{
    int cnt=0;
    q.push(point {1,1});
    int tot1=1;
    int tot2=0;
    ans[cnt++]=map[1][1]-'0';

    while(!q.empty())
    {
        old=q;
        int t=tot1;
        while(t--)
        {
            point temp=q.front();
            q.pop();

            if(inmap(temp.x,temp.y+1)&&map[temp.x][temp.y+1]=='0')
            {
                q.push(point {temp.x,temp.y+1});
                tot2++;
            }

            if(inmap(temp.x+1,temp.y)&&map[temp.x+1][temp.y]=='0')
            {
                q.push(point {temp.x+1,temp.y});
                tot2++;
            }
        }
        if(tot2==0)
        {
            ans[cnt++]=1;
            int t=tot1;
            while(t--)
            {
                point temp=old.front();
                old.pop();
                if(inmap(temp.x,temp.y+1))
                {
                    q.push(point {temp.x,temp.y+1});
                    tot2++;
                }
                if(inmap(temp.x+1,temp.y))
                {
                    q.push(point {temp.x+1,temp.y});
                    tot2++;
                }
            }
        }
        else
            ans[cnt++]=0;
        tot1=tot2;
        tot2=0;
    }
    while(!old.empty())
        old.pop();
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> h >> w;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                cin >> map[i][j];
        bfs();
        int i;
        for(i=0; ans[i]==0; i++)
            ;
        for(; i<=w-1+h-1; i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}
