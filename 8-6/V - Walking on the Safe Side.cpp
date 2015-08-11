#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

int H,W;
int map[10100][10100];
int dp[10100][10100];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(map,0,sizeof(map));
        cin >> H >> W;
        getchar();
        for(int i=1; i<=H; i++)
        {
            string temp;
            getline(cin,temp);
            istringstream is(temp);
            int a,b;
            is >> a;
            while(is>>b)
                map[a][b]=1;
        }
        dp[1][0]=1;
        for(int i=1; i<=H; i++)
            for(int j=1; j<=W; j++)
                if(map[i][j])
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
        cout << dp[H][W] << endl;
        if(T)
            cout << endl;
    }
    return 0;
}
