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
#define MAXN 1000100
using namespace std;

string temp;
char str[MAXN<<1];
int lentemp,len;
int p[MAXN<<1];

int main()
{
    int N=0;
    cin.sync_with_stdio(false);
    while(cin >> temp)
    {
        if(temp=="END")
            break;

        memset(p,0,sizeof(p));
        lentemp=temp.length();
        len=(lentemp<<1)+2;
        str[0]='@';

        for(int i=0; i<=lentemp; i++)
        {
            str[2*i+2]=temp[i];
            str[2*i+1]='#';
        }
        //cout << str << endl;

        int maxx=0;
        int id;
        int ans=0;
        for(int i=1; i<len; i++)
        {
            if(maxx>i)
                p[i]=min(p[2*id-i],maxx-i);
            else
                p[i]=1;
            while(str[i-p[i]]==str[i+p[i]])
                p[i]++;
            if(maxx<i+p[i])
            {
                maxx=i+p[i];
                id=i;
            }
            ans=max(ans,p[i]);
            //cout << ans << endl;
        }
        cout << "Case " << ++N << ": " << ans-1 << endl;
    }
    return 0;
}
