#include <iostream>
#include <cstdio>
int start,stop;
int n,m;
int step;
int a,b;
int temp;

using namespace std;

bool check(int i,int a,int b)
{
    if(i>=a&&i<=b)
        return true;
    return false;
}

int main()
{
    cin >> n >> m >> start >> stop;
    cin >> temp;
    if(start<stop)
    {
        for(int i=start,step=1; i!=stop; step++)
        {
            if(step==temp)
            {
                scanf("%d%d",&a,&b);
                if(check(i,a,b)||check(i+1,a,b))
                    printf("X");
                else
                {
                    i++;
                     printf("R");
                }
                scanf("%d",&temp);
            }
            else
            {
                i++;
                printf("R");
            }
        }
        while(~scanf("%d",&temp));
    }
    else
    {
        for(int i=start,step=1; i!=stop; step++)
        {
            if(step==temp)
            {
                scanf("%d%d",&a,&b);
                if(check(i,a,b)||check(i-1,a,b))
                   printf("X");
                else
                {
                    i--;
                     printf("L");
                }
                scanf("%d",&temp);
            }
            else
            {
                i--;
                printf("L");
            }
        }
        while(~scanf("%d",&temp));
    }
    return 0;
}
