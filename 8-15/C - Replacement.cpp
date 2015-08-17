#include <iostream>
#include <cstdio>
using namespace std;

char str[300100];
int m,n;
int ans=0;
int cnt=0;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);

    for(int i=1; i<=n; i++)
        if(str[i]=='.')
            cnt++;
        else
        {
            if(cnt>1)
                ans=ans+cnt-1;
            cnt=0;
        }
    if(cnt>1)
        ans=ans+cnt-1;

    while(m--)
    {
        int pos;
        char temp;
        scanf("%d %c",&pos,&temp);

        if(temp=='.')
        {
            if(str[pos]!='.')
            {
                if(str[pos-1]=='.')
                    ans++;
                if(str[pos+1]=='.')
                    ans++;
            }
            str[pos]=temp;
        }
        else
        {
            if(str[pos]=='.')
            {
                if(str[pos-1]=='.')
                    ans--;
                if(str[pos+1]=='.')
                    ans--;
            }
            str[pos]=temp;
        }

        printf("%d\n",ans);
    }
    return 0;
}
