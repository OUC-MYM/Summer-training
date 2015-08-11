#include <iostream>
#include <cstring>
#define INF 1<<30
using namespace std;

int N;
int H;

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N)
    {
        int dp[N+1];
        memset(dp,0,sizeof(dp));
        int cnt=0;

        for(int i=0; i<N; i++)
        {
            cin >> H;
            int flag=0;
            int temp=INF;
            int sign;
            for(int j=1; j<=cnt; j++)
                if(H<=dp[j])
                {
                    flag=1;
                    if(temp>dp[j]-H)
                    {
                        temp=dp[j]-H;
                        sign=j;
                    }
                }
            if(!flag)
                dp[++cnt]=H;
            else
                dp[sign]=H;
        }

        cout << cnt << endl;
    }
    return 0;
}
