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
    int T;
    cin >> T;
    while(T--)
    {
        memset(v,0,sizeof(v));
        cin >> N1 >> N2;
        while(N2--)
        {
            int x,y;
            cin >> x >> y;
            v[x][y]=1;
        }
        N2=N1;
        cout << N1-solv() << endl;
    }
    return 0;
}
