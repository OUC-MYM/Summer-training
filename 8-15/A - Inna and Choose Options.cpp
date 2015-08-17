#include <iostream>
using namespace std;

char str[15];
int ans[15];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int cnt=0;
        int flag;

        cin >> str+1;

        for(int k=12; k>=1; k--)
        {
            if(12%k)
                continue;
            for(int i=1; i<=k; i++)
            {
                flag=1;
                for(int j=i; j<=12; j=j+k)
                    if(str[j]=='O')
                        flag=0;
                if(flag)
                {
                    ans[++cnt]=k;
                    break;
                }
            }
        }
        cout << cnt << " ";
        for(int i=1; i<=cnt; i++)
            cout << 12/ans[i] << "x" << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
