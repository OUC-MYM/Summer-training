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

double n,m;


int main()
{
   //cin.sync_with_stdio(false);
   while(cin >> n >> m)
   {
       double sum=0;
       while(m--)
       {
           sum=sum+n;
           n=sqrt(n);
       }
       printf("%.2f\n",sum);
   }
   return 0;
}
