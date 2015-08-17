#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 1<<30
#define MAXN 10010
using namespace std;


int N,M,sum,flag;
int pre[MAXN];
struct point
{
    int a;
    char ch;
    int b;
} p[MAXN];

int find (int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}



int tuoposort(int n,int mat[][sum])
{
    int d[sum],i,j,k;

    for(i=0; i<n; i++)
        for(d[i]=j=0; j<n; d[i]+=mat[j++][i])
            ;

    for(k=0; k<n; k++)
    {
        int cnt=0;
        for(i=0; i<n; i++)
        {
            if(d[i]==0)
                cnt++;
            if(cnt>1)
            {
                flag=1;
                break;
            }
        }
        for(i=0; d[i]&&i<n; i++)
            ;
        if(i==n)
            return 0;
        for(d[i]=-1,j=0; j<n; j++)
            d[j]-=mat[i][j];
    }
    return 1;
}

void unions(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
        pre[x]=y;
}


int main()
{
    while(cin >> N >> M)
    {
        flag=0;

        for(int i=0; i<N; i++)
            pre[i]=i;

        sum=0;

        for(int i=1; i<=M; i++)
        {
            int a,b;
            char ch;
            cin >> a >> ch >> b;
            if(ch=='=')
                unions(a,b);
            p[sum].a=a;
            p[sum].ch=ch;
            p[sum++].b=b;
        }

        int map[sum][sum];
        memset(map,0,sizeof(map));


        for(int i=0; i<sum; i++)
        {
            if(p[i].ch=='=')
                continue;
            if(p[i].ch=='>')
                map[pre[p[i].a]][pre[p[i].b]]=1;
            if(p[i].ch=='<')
                map[pre[p[i].b]][pre[p[i].a]]=1;
        }

        bool check=tuoposort(sum,map);
        if(!flag&&check)
            cout << "OK" << endl;
        else if(flag&&check)
            cout << "UNCERTAIN" << endl;
        else
            cout << "CONFLICT" << endl;
    }
    return 0;
}
