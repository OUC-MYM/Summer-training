#include <iostream>
using namespace std;

int N,M;
int pre[1010];

int find (int x)
{
    if(pre[x]==x)
        return x;
    else
        return find(pre[x]);
}

int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;

        for(int i=1; i<=N; i++)
            pre[i]=i;

        cin >> M;
        int x,y;
        int a,b;
        while(M--)
        {
            cin >> a >> b;
            x=find(a);
            y=find(b);
            if(pre[x]!=pre[y])
                pre[x]=y;
        }

        int ans=0;
        for(int i=1; i<=N; i++)
            if(pre[i]==i)
                ans++;
        cout << ans << endl;
    }
    return 0;
}
