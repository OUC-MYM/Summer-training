#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#define MAXN 2010
using namespace std;

bool map[MAXN][MAXN];
int in[MAXN];
int N,M,cnt;


void topo(int n)
{
    queue<int> q;
    cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        cnt++;
        for(int i=1; i<=n; i++)
        {
            if(map[v][i])
            {
                in[i]--;
                if(!in[i])
                    q.push(i);
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int T;
    int tot=0;
    cin >> T;
    while(T--)
    {
        cin>> N;
        memset(map,0,sizeof map);
        memset(in,0,sizeof in);

        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
            {
                char temp;
                cin >> temp;
                if(temp=='1')
                {
                    map[i][j]=1;
                    in[j]++;
                }
            }
        topo(N);
        cout << "Case #" << ++tot << ": " ;
        if(cnt==N)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
