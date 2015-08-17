#include <iostream>
#include <cstdio>
using namespace std;

int N;

int pre[10000010];
int num[10000010];

int find (int x)
{
    if(pre[x]==x)
        return x;
    else
        pre[x]=find(pre[x]);
    return pre[x];
}

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    while(~scanf("%d",&N))
    {
        if(N==0)
        {
            printf("1\n");
            continue;
        }
        for(int i=1; i<=10000000; i++)
            pre[i]=i,num[i]=1;

        int a,b,x,y;

        int MAX=0;
        while(N--)
        {
            scanf("%d%d",&a,&b);
            MAX=max(MAX,a);
            MAX=max(MAX,b);
            x=find(a);
            y=find(b);
            if(x!=y)
            {
                pre[x]=y;
                num[y]=num[x]+num[y];
            }
        }
        int ans=0;
        for(int i=1; i<=MAX; i++)
            ans=max(ans,num[i]);
        printf("%d\n",ans);
    }
    return 0;
}
