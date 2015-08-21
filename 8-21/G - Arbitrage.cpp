#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 1<<30
using namespace std;

int N,M;
int cnt;
double w[35][35];
map<string,int> name;

void floyd(int n)
{
    int i,j,k;
    float temp;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                w[i][j]=max(w[i][j],w[i][k]*w[k][j]);
                if(i==j && w[i][j]>1)
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
    cout << "No" << endl;
}


int main()
{
    cin.sync_with_stdio(false);
    int T=0;
    while(cin >> N && N)
    {
        memset(w,0,sizeof(w));
        name.clear();
        cnt=0;
        for(int i=1; i<=N; i++)
        {
            string temp;
            cin >> temp;
            name[temp]=++cnt;
        }
        cin >> M;
        for(int i=1; i<=M; i++)
        {
            string a,b;
            double c;
            cin >> a >> c >> b;
            w[name[a]][name[b]]=c;
        }
        cout << "Case " << ++T << ": ";
        floyd(N);
    }
    return 0;
}
