#include <iostream>

using namespace std;

int N,M;
int cnt;
int sta[65];
int rsum[65];
int map[110];
int dp[110][65][65];

int cal(int i)
{
    int tot=0;
    while(i)
    {
        tot++;
        i=i&(i-1);
    }
    return tot;
}

void solv()
{
    cnt=0;
    for(int i=0; i<(1<<M); i++)
    {
        if(i&(i<<1)||i&(i<<2))
            continue;
        sta[++cnt]=i;
        rsum[cnt]=cal(i);
    }
}

int main()
{
    while(cin >> N >> M)
    {
        for(int i=1; i<=N; i++)
        {
            char temp[15];
            cin >> temp;
            for(int j=0; j<M; j++)
                if(temp[j]=='H')
                    map[i]=map[i]*2+1;
                else
                    map[i]=map[i]*2;
        }

        solv();

        for(int i = 1; i <= cnt; i ++)
        {
            if(map[1]&sta[i])
                continue;
            dp[1][i][1]=max(dp[1][i][1],rsum[i]);
        }


        for(int i=2; i<=N; i++)
        {
            for(int j=1; j<=cnt; j++)
            {
                if(map[i]&sta[j])
                    continue;
                for(int k=1; k<=cnt; k++)
                {
                    if(sta[j]&sta[k])
                        continue;
                    for(int t=1; t<=cnt; t++)
                    {
                        if(sta[j]&sta[t])
                            continue;
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+rsum[j]);
                    }
                }
            }
        }

        int ans=0;
        for(int i=1; i<=cnt; i++)
            for(int j=1; j<=cnt; j++)
                ans=max(ans,dp[N][i][j]);
        cout << ans << endl;
    }
    return 0;
}
