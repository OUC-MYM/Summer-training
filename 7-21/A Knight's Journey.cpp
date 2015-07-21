#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int map[30][30];

int dirX[]= {-2,-2,-1,-1,1,1,2,2};
int dirY[]= {-1,1,-2,2,-2,2,-1,1};
int ok;
int p,q;
char ans[60];

bool inmap(int x,int y)
{
    if(x>q||y>p||x<=0||y<=0)
        return false;
    return true;
}

void dfs(int x,int y,int n)
{
    if(ok)
        return;

    ans[2*n-1]=x+'A'-1;
    ans[2*n]=y+'0';

    if(n==p*q)
    {
        ok=1;
        return;
    }
    int Ix,Iy;
    for(int i=0; i<8; i++)
    {
        Ix=x+dirX[i];
        Iy=y+dirY[i];
        if(inmap(Ix,Iy)&&!map[Ix][Iy])
        {
            map[Ix][Iy]=1;
            dfs(Ix,Iy,n+1);
            map[Ix][Iy]=0;
        }
    }
    return;
}

void solv()
{
    memset(map,0,sizeof(map));
    memset(ans,0,sizeof(ans));
    ok=0;
    map[1][1]=1;
    dfs(1,1,1);
    if(ok==1)
        {
            for(int i=1;i<=2*q*p;i++)
                cout << ans[i];
            cout << endl;
        }
    else
        cout << "impossible" << endl;
}
int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        cin >> p >> q;
        cout << "Scenario #" << i << ":" <<endl;
        solv();
        if(i!=T)
            cout << endl;
    }
    return 0;
}
