#include <iostream>
#include <cstring>
using namespace std;

int sum;
int N;
int take[15];
bool dp[1000100];

int main()
{
    cin.sync_with_stdio(false);
    while(cin >> sum)
    {
        memset(dp,0,sizeof(dp));
        cin >> N;
        for(int i=0; i<N; i++)
        {
            cin >> take[i];
            dp[take[i]]=1;
        }

        for(int i=1; i<=sum; i++)
            for(int j=0; j<N; j++)
                if(i-take[j]>=0&&dp[i-take[j]]==0)
                {
                    dp[i]=1;
                    break;
                }

        if(dp[sum])
            cout << "Stan wins" <<endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}
