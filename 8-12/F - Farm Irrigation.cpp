#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int M,N;
char map[55][55];
int pre[55*55];

int R[11][11]= {{0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,1,1,1,0,1},{0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,1,1,1,0,1},{0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,1,1,1,0,1},{1,0,1,0,0,1,1,1,1,0,1},{0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,1,1,1,0,1},{1,0,1,0,0,1,1,1,1,0,1},{1,0,1,0,0,1,1,1,1,0,1}};

int U[11][11]= {{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,1,1}};


int find(int x)
{
    if(pre[x]==x)
        return x;
    else
        pre[x]=find(pre[x]);
    return pre[x];
}

void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
        pre[x]=y;
}

int main()
{
    while(~scanf("%d%d",&M,&N))
    {
        if(M==-1&&N==-1)
            break;

        memset(map,0,sizeof(map));

        for(int i=0; i<M*N; i++)
            pre[i]=i;

        for(int i=0; i<M; i++)
            scanf("%s",map[i]);

        for(int i=0; i<M; i++)
            for(int j=1; j<N; j++)
                if(R[map[i][j-1]-'A'][map[i][j]-'A'])
                    Union(i*N+j-1,i*N+j);

        for(int i=0; i<N; i++)
            for(int j=1; j<M; j++)
                if(U[map[j-1][i]-'A'][map[j][i]-'A'])
                    Union((j-1)*N+i,j*N+i);

        int ans=0;
        for(int i=0; i<M*N; i++)
            if(pre[i]==i)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
