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
int fa_a[10010],fa_b[10010];

int find_a(int x)
{
    if(fa_a[x]==1)
        return 1;
    if(x!=fa_a[x])
        fa_a[x]=find_a(fa_a[x]);
    return fa_a[x];
}

int find_b(int x)
{
    if(fa_b[x]==1)
        return 1;
    if(x!=fa_b[x])
        fa_b[x]=find_b(fa_b[x]);
    return fa_b[x];
}

void link(int x,int y)
{
    if(x!=1)
        fa_a[x]=find_a(y);
    if(y!=1)
        fa_b[y]=find_b(x);
}


int main()
{
    cin.sync_with_stdio(false);
    while(cin >> N >> M && (N||M))
    {
        for(int i=1; i<=N; i++)
            fa_a[i]=fa_b[i]=i;

        while(M--)
        {
            int a,b;
            cin >> a >> b;
            link(a,b);
        }

        int flag=0;
        for(int i=1; i<=N; i++)
            if(find_a(i)!=1)
            {
                flag=1;
                break;
            }
        for(int i=1; i<=N; i++)
            if(find_b(i)!=1)
            {
                flag=1;
                break;
            }

        cout << (flag?("No"):("Yes")) << endl;
    }
    return 0;
}
