#include <iostream>
#include <cstring>
using namespace std;

int M,N;
int R[1010],L[1010];
int H[1010][1010];


int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        memset(R,0,sizeof(R));
        memset(L,0,sizeof(L));
        memset(H,0,sizeof(H));

        int ans=0;

        cin >> M >> N;
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                char temp;
                cin >> temp;
                if(temp=='F')
                    H[i][j]=H[i-1][j]+1;
                else
                    H[i][j]=0;
                L[j]=R[j]=j;
            }
            for(int j=1; j<=N; j++)
                if(H[i][j])
                    while(H[i][L[j]-1]>=H[i][j])
                        L[j]=L[L[j]-1];

            for(int j=N; j>=1; j--)
                if(H[i][j])
                    while(H[i][R[j]+1]>=H[i][j])
                        R[j]=R[R[j]+1];

            for(int j=1; j<=N; j++)
                ans = max(ans,H[i][j]*(R[j]-L[j]+1));
        }
        cout << ans*3 << endl;
    }
    return 0;
}
