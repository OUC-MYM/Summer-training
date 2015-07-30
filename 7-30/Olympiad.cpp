#include <iostream>

using namespace std;

int dis[1500];

bool check(int n)
{
    bool vis[10]= {false};
    while(n)
    {
        if(vis[n%10])
            return false;
        vis[n%10]=true;
        n=n/10;
    }
    return true;
}

void solv()
{
    int cnt=0;
    for(int i=1; i<=100000; i++)
    {

        if(i%100==0)
        {
            dis[i/100]=cnt;
            cnt=0;
        }
        if(check(i))
            cnt++;
    }
}

int main()
{
    solv();
    int T,a,b,ans;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        ans=0;
        int p1,p2;

        p1=a/100+1;
        p2=b/100+1;
        for(int i=p1+1; i<=p2-1; i++)
            ans=ans+dis[i];
        if(p1!=p2)
        {
            if(a%100==0)a++;
            for(int i=a; i%100; i++)
                if(check(i))
                    ans++;
            for(int i=b; i%100; i--)
                if(check(i))
                    ans++;
        }
        else
            for(int i=a; i<=b; i++)
                if(check(i))
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
