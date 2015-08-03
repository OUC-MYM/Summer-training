#include <iostream>
#include <cstring>
using namespace std;

int N1,N2;
int v[210][210];
bool vis[210];
int father[210];

bool link(int n)
{
    for(int i=1; i<=N2; i++)
        if(v[n][i]&&!vis[i])
        {
            vis[i]=1;
            if(father[i]==0||link(father[i]))
            {
                father[i]=n;
                return true;
            }
        }
    return false;
}

int solv()
{
    int cnt=0;
    memset(father,0,sizeof(father));
    for(int i=1; i<=N1; i++)
    {
        memset(vis,0,sizeof(vis));
        if(link(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    while(cin >> N1 >> N2)
    {
        memset(v,0,sizeof(v));
        for(int i=1; i<=N1; i++)
        {
            int temp;
            cin >> temp;
            while(temp--)
            {
                int temp2;
                cin >> temp2;
                v[i][temp2]=1;
            }
        }
        cout << solv() << endl;
    }
    return 0;
}
