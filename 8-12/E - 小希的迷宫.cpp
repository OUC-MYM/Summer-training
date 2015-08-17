#include<stdio.h>
#define MAX 100100
int pre[MAX];
int sign[MAX];

int find (int x)
{
    if(pre[x]==x)
        return x;
    else
        return find(pre[x]);
}

int main()
{

    while(1)
    {
        for(int i=1; i<=MAX; i++)
        {
            pre[i]=i;
            sign[i]=0;
        }

        int a,b;
        int go=1;
        int flag=1;

        while(1)
        {

            scanf("%d %d",&a,&b);
            if(a==0&&b==0)
                break;
            if(a==-1&&b==-1)
            {
                go=0;
                break;
            }

            int x=find(a);
            int y=find(b);
            if(x!=y)
                pre[x]=y;
            else
                flag=0;
            sign[a]=sign[b]=1;
        }

        if(!go)
            break;

        int k=0;
        for(int i=1; i<=MAX; i++)
        {

            if(sign[i]&&pre[i]==i)
                  k++;
            if(k>1)
                  flag=0;
        }

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
