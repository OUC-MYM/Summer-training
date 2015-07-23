#include <iostream>
#include <cstdio>
#define INF 1111111111111111111
using namespace std;

int n;
int ok;
unsigned long long ans;

void dfs(unsigned long long i)
{
    if(i>INF)
        return;

    if(ok)
        return;

    if(i%n==0)
    {
        ok=1;
        ans=i;
        return;
    }

    dfs(i*10);
    dfs(i*10+1);
}

int main()
{
    while(cin>>n && n)
    {
        ans=1;
        ok=0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
