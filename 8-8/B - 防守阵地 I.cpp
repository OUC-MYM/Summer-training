#include <iostream>

using namespace std;

int people[1000100];
int Sn[1000100];
int SSn[1000100];

int N,M;


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> M)
    {
        Sn[0]=0;
        SSn[0]=0;
        for(int i=1; i<=N; i++)
        {
            cin >> people[i];
            Sn[i]=Sn[i-1]+people[i];
            SSn[i]=SSn[i-1]+Sn[i];
        }

        int sum;
        int ans=0;
        for(int i=M; i<=N; i++)
        {
            sum=M*Sn[i]-(SSn[i-1]-SSn[i-1-M]);
            ans=max(ans,sum);
        }
        cout << ans << endl;
    }
    return 0;
}
