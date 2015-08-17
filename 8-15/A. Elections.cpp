#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int num[110];

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int old=0,ne;
        int sign=1;
        for(int j=1; j<=n; j++)
        {
            cin >> ne;
            if(ne>old)
            {
                old=ne;
                sign=j;
            }
        }
        num[sign]++;
    }

    int ans=0;
    int sign=1;
    for(int j=1; j<=n; j++)
        if(num[j]>ans)
            {
                ans=num[j];
                sign=j;
            }
    cout << sign << endl;
    return 0;
}
