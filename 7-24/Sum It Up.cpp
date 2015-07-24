#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int TOSUM;
int N;
int n[15];
int ans[15];
int sum;
int ok;

bool cmp(int a, int b)
{
    return a>b;
}

void dfs(int pos,int tot,int cnt)
{
    if(tot==TOSUM)
    {
        ok=1;
        for(int i=0; i<cnt; i++)
        {
            if(i==cnt-1)
                cout << ans[i] <<endl;
            else
                cout << ans[i] << "+";
        }
    }

    if(tot>TOSUM)
        return;

    int temp=-1;
    for(int i=pos; i<N; i++)
    {
        if(temp!=n[i])
        {
            ans[cnt]=n[i];
            temp=n[i];
            dfs(i+1,tot+n[i],cnt+1);
        }
    }
    return;
}

int main()
{
    while(cin >> TOSUM >> N && (TOSUM||N))
    {
        sum=0;
        ok=0;
        memset(ans,0,sizeof(ans));

        for(int i=0; i<N; i++)
        {
            cin >> n[i];
            sum=sum+n[i];
        }

        if(sum<TOSUM)
        {
            cout << "Sums of " << TOSUM << ":" << endl << "NONE" << endl;
            continue;
        }

        sort(n,n+N,cmp);

        cout << "Sums of " << TOSUM << ":" << endl;
        dfs(0,0,0);

        if(!ok)
            cout << "NONE" << endl;
    }
    return 0;
}
