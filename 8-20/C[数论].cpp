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

int N;

int main()
{
   cin.sync_with_stdio(false);
   while(cin >> N && N)
   {
      cout << (N-1)/2 << endl;
   }
   return 0;
}
