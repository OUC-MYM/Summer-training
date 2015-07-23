#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int ans[5000];
short vis[860000000];
int cnt;

void slov()
{
    ans[1]=1;
    cnt = 2;
    queue <int> q;
    q.push(ans[1]);
    while(!q.empty())
    {
        long long temp=q.front();
        q.pop();

        //cout << "pop:" << temp << " " << cnt << endl;

        if(temp*2<=859963392&&!vis[temp*2])
        {
            ans[cnt]=temp*2;
            q.push(ans[cnt++]);
            vis[temp*2]=1;
        }

        if(temp*3<=859963392&&!vis[temp*3])
        {
            ans[cnt]=temp*3;
            q.push(ans[cnt++]);
            vis[temp*3]=1;
        }

        if(temp*5<=859963392&&!vis[temp*5])
        {
            ans[cnt]=temp*5;
            q.push(ans[cnt++]);
            vis[temp*5]=1;
        }

        if(cnt > 1500)
            break;
    }

    sort (ans,ans+cnt);
}

int main()
{
    slov();
    int n;
    while(cin >> n && n)
    {
        cout << ans[n] << endl;
    }
    return 0;
}

//   859963392
