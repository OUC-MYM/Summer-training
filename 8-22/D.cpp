#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 0x3f3f3f3f
#define MAXN 2500
using namespace std;

int n,num,cnt;
int vis[100010];
int ans[100010];
struct point
{
    int id;
    int s;
    int e;
    friend bool operator < (point a,point b)
    {
        return a.e>b.e;
    }
} p[100010];

bool cmp(point a,point b)
{
    return a.s<b.s;
}

int main()
{
    //cin.sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        priority_queue <point> q;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            p[i].id=i+1;
            scanf("%d",&p[i].s);
        }
        for(int i=0; i<n; i++)
            scanf("%d",&p[i].e);
        sort(p,p+n,cmp);

        num=cnt=0;
        {
            int i=0;
            for(int j=0; j<n; j++)
            {
                while(i<n)
                {
                    if(p[i].s > num)
                        break;
                    q.push(p[i]);
                    i++;
                }
                while(!q.empty())
                {
                    point temp=q.top();
                    if(temp.e>=num)
                    {
                        ans[cnt++]=temp.id;
                        vis[temp.id]=1;
                        q.pop();
                        num++;
                        break;
                    }
                    else
                        q.pop();
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=0; i<cnt; i++)
            printf("%d ",ans[i]);
        for(int i=1; i<=n; i++)
            if(!vis[i])
                printf("%d ",i);
        printf("\n");
    }
    return 0;
}

/*
7 6 5 2 4 1 8 3
6 4 3 1 2 7 8 5
6 7 2 3 8 4 1 5
1 2 3 4 5 6 7 8
*/
