#include <iostream>
#include <cstring>
using namespace std;

bool vs[2010][2010];
bool vis[2010];
int n;

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> n)
    {
        bool ok=1;
        memset(vs,0,sizeof(vs));

        for(int j=1; j<=n-1; j++)
        {
            memset(vis,0,sizeof(vis));
            for(int i=1; i<=n/2; i++)
            {
                int a,b;
                cin >> a >> b;
                b=-b;
                if(vis[a]||vis[b]||a==b)
                    ok=0;
                vis[a]=1;
                vis[b]=1;
                if(vs[a][b])
                    ok=0;
                vs[a][b]=vs[b][a]=1;
            }
        }

        if(ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

/*
2
1-2
4
1-2 3-4
1-3 2-4
1-4 2-3
4
1-3 2-4
1-3 2-4
1-4 2-3
4
1-2 3-2
1-3 2-4
1-4 2-3
*/

