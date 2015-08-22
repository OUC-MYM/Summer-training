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
#define INF 0x3f3f3f3f
#define MAXN 2500
using namespace std;

int N;
double ans[MAXN];
double mi[MAXN];

void powll()
{
    mi[1]=2;
    mi[2]=4;
    for(int i=3;i<=1010;i++)
        mi[i]=mi[i-2]*double(2);
}

void lists()
{
    powll();
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    for(int i=4;i<=1010;i++)
        ans[i]=ans[i-2]+mi[i-3];
}


int main()
{
   //cin.sync_with_stdio(false);
   lists();
   while(cin >> N)
   {
       printf("%.0f\n",ans[N]);
   }
   return 0;
}
