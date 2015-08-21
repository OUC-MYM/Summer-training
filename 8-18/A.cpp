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
#define MAX 100000
using namespace std;

int prime[MAX];
int num=0;
int v[MAX];
void primelist()
{
    for(int i=2; i<MAX; i++)
        if(!v[i])
        {
            prime[num++]=i;
            for(int j=2*i; j<MAX; j=j+i)
                v[j]=1;
        }
}


int main()
{
    cin.sync_with_stdio(false);
    primelist();
    int T;
    cin >> T;
    while(T--)
    {
       int N;
       cin >> N;
       if(N==4)
       {
           cout << 2 << endl;
           continue;
       }
       int flag=0;
       for(int i=0;i<num && prime[i]*prime[i]<N;i++)
       {
           if(N%prime[i]==0)
           {
               flag=1;
               break;
           }
       }
       if(flag)
        cout << 0 << endl;
       else
        cout << N-1 << endl;
    }
    return 0;
}
