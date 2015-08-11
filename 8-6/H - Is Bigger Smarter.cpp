#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010],ans[1010],tot=-1,sign;

struct elephant
{
    int w;
    int s;
    int pos;
} e[1010];

bool cmp(elephant a,elephant b)
{
    return a.w<b.w;
}

void print(int sign,int tot)
{
    if(tot==0)
        return;
    print(ans[sign],tot-1);
    cout << e[sign].pos << endl;
}

int main()
{
    int cnt=0;
    while(cin >> e[cnt].w >> e[cnt].s)
    {
        e[cnt].pos=cnt+1;
        cnt++;
    }
    sort(e,e+cnt,cmp);

    for(int i=0; i<cnt; i++)
    {
        dp[i]=1;
        ans[i]=i;
    }


    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<i; j++)
            if(e[i].w>e[j].w&&e[j].s>e[i].s)
            {
                if(dp[i]<dp[j]+1)
                    ans[i]=j;
                dp[i]=max(dp[i],dp[j]+1);
            }
        if(dp[i]>tot)
            sign=i;
        tot=max(tot,dp[i]);
    }

    //for(int i=0; i<cnt; i++)
    //cout << e[i].w << "|" << e[i].s << "|" << e[i].pos << endl;

    cout << tot << endl;
    print(sign,tot);
    return 0;
}



