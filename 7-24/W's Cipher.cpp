#include <iostream>
#include <cstring>
using namespace std;

int k1,k2,k3;
char str[100];
int len;
int vis[100];
int cnt;

int main()
{
    while(cin >> k1 >> k2 >> k3 && (k1||k2||k3))
    {
        cin >> str;
        len=strlen(str);

        cnt=0;
        for(int i=0; i<len; i++)
            if(str[i]>='a'&&str[i]<='i')
                vis[++cnt]=i;
        if(cnt)
        {
            for(int k=0; k<k1; k++)
            {
                char temp=str[vis[cnt]];
                for(int i=cnt; i>1; i--)
                    str[vis[i]]=str[vis[i-1]];
                str[vis[1]]=temp;
            }
        }

        cnt=0;
        for(int i=0; i<len; i++)
            if(str[i]>='j'&&str[i]<='r')
                vis[++cnt]=i;
        if(cnt)
        {
            for(int k=0; k<k2; k++)
            {
                char temp=str[vis[cnt]];
                for(int i=cnt; i>1; i--)
                    str[vis[i]]=str[vis[i-1]];
                str[vis[1]]=temp;
            }
        }

        cnt=0;
        for(int i=0; i<len; i++)
            if(str[i]=='_'||str[i]>='s'&&str[i]<='z')
                vis[++cnt]=i;

        if(cnt)
        {
            for(int k=0; k<k3; k++)
            {
                char temp=str[vis[cnt]];
                for(int i=cnt; i>1; i--)
                    str[vis[i]]=str[vis[i-1]];
                str[vis[1]]=temp;
            }
        }
        cout << str << endl;
    }
    return 0;
}
