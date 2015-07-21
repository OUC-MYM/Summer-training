#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int N,A,B;
struct que
{
    int i;
    int step;
};
int n[210];
int vis[210];


int bfs(int i)
{
    queue <que> q;
    q.push(que {i,0});
    while(!q.empty())
    {
        que temp=q.front();
        q.pop();
        if(temp.i==B)
            return temp.step;

        vis[temp.i]=1;
        if(temp.i+n[temp.i]<=N&&!vis[temp.i+n[temp.i]])
            q.push(que {temp.i+n[temp.i],temp.step+1});
        if(temp.i-n[temp.i]>0&&!vis[temp.i-n[temp.i]])
            q.push(que {temp.i-n[temp.i],temp.step+1});
    }
    return -1;
}

int main()
{
    while(~scanf("%d",&N)&&N)
    {
        scanf("%d%d",&A,&B);
        for(int i=1; i<N+1; i++)
            scanf("%d",&n[i]);
        memset(vis,0,sizeof(vis));
       printf("%d\n",bfs(A));
    }
    return 0;
}
