#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K,W;
int ans;
int ok;

struct stones
{
    int val;
    int wgt;
} s[25];


void dfs(int pos,int cnt,int vl,int wg)
{
    //if(ok)
        //return;
        //cout << pos << cnt << vl << wg << endl;
    if(wg>W)
        return;
    if(cnt==K)
    {
        //ok=1;
        ans=max(ans,vl);
        return;
    }
    for(int i=pos;i<=N;i++)
        {
            //cout << vl << " " << s[i].val << endl;
            dfs(i+1,cnt+1,vl+s[i].val,wg+s[i].wgt);
        }
}

bool cmp(stones a,stones b)
{
    return a.val>b.val;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ans=0;
        //ok=0;

        cin >> N >> K;
        for(int i=1; i<=N; i++)
            cin >> s[i].val >> s[i].wgt;
        cin >> W;

        //for(int i=1; i<=N; i++)
            //cout << s[i].val << s[i].wgt<<endl;

        sort(s+1,s+N+1,cmp);
        dfs(1,0,0,0);
        cout << ans << endl;
    }
    return 0;
}

/*
1
2 2
1 2
2 56
1000
*/

