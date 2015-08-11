#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,X,Y,MAX,M;
int dp[1010][2];
struct Board
{
    int L;
    int R;
    int H;
} B[1010];

bool cmp(Board a,Board b)
{
    return a.H>b.H;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(dp,999999,sizeof(dp));

        cin >> N >> X >> Y >> MAX >> M;

        for(int i=0; i<N; i++)
            cin >> B[i].L >> B[i].R >> B[i].H;
        B[N].L=B[N].R=X,B[N].H=Y;
        B[N+1].L=0,B[N+1].R=1000,B[N+1].H=0;
        sort(B,B+N+1,cmp);
        dp[0][0]=dp[0][1]=0;

        for(int i=0; i<=N; i++)
        {
            bool flagL=0,flagR=0;
            for(int j=i+1; j<=N+1; j++)
            {
                if(B[i].H-B[j].H > MAX)
                    break;

                if(B[i].L>=B[j].L && B[i].L <= B[j].R && !flagL)
                {
                    flagL=1;
                    if(j!=N+1)
                    {
                        dp[j][0] = min(dp[j][0], dp[i][0]+B[i].H-B[j].H+B[i].L-B[j].L);
                        dp[j][1] = min(dp[j][1], dp[i][0]+B[i].H-B[j].H+B[j].R-B[i].L);
                    }
                    else
                    {
                        dp[j][0] = min(dp[j][0], dp[i][0]+B[i].H-B[j].H);
                        dp[j][1] = min(dp[j][1], dp[i][0]+B[i].H-B[j].H);
                    }
                }
                if(B[i].R>=B[j].L && B[i].R <= B[j].R && !flagR)
                {
                    flagR=1;
                    if(j != N+1)
                    {
                        dp[j][0] = min(dp[j][0], dp[i][1]+B[i].H-B[j].H+B[i].R-B[j].L);
                        dp[j][1] = min(dp[j][1], dp[i][1]+B[i].H-B[j].H+B[j].R-B[i].R);
                    }
                    else
                    {
                        dp[j][0] = min(dp[j][0], dp[i][1]+B[i].H-B[j].H);
                        dp[j][1] = min(dp[j][1], dp[i][1]+B[i].H-B[j].H);
                    }
                }
            }
        }

        if(dp[N+1][0]<=M||dp[N+1][1]<=M)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
