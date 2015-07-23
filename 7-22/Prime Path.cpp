#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int vis[10000];
int v[10000];
int viss[10000];
void primelist()
{
    for(int i=2; i<10000; i++)
        if(!vis[i])
        {
            v[i]=1;
            for(int j=2*i; j<10000; j=j+i)
                vis[j]=1;
        }
}

struct que
{
    int n;
    int step;
};

int bfs(int s,int e)
{
    queue <que> q;
    q.push(que {s,0});

    que temp;

    while(!q.empty())
    {
        temp=q.front();
        //cout << temp.n << " " << temp.step << endl;
        if(temp.n==e)
            return temp.step;


        temp.n=temp.n%1000;
        for(int i=1000; i<=9000; i=i+1000)
            if(!viss[temp.n+i]&&v[temp.n+i])
                {
                    q.push(que {temp.n+i,temp.step+1});
                    viss[temp.n+i]=1;
                }


        temp=q.front();
        int k=temp.n/1000;
        temp.n=temp.n%100;
        for(int i=0; i<=900; i=i+100)
            if(!viss[temp.n+k*1000+i]&&v[temp.n+k*1000+i])
                {
                    q.push(que {temp.n+k*1000+i,temp.step+1});
                    viss[temp.n+k*1000+i]=1;
                }

        temp=q.front();
        int l=temp.n/100;
        temp.n=temp.n%10;
        for(int i=0; i<=90; i=i+10)
            if(!viss[temp.n+l*100+i]&&v[temp.n+l*100+i])
               {
                   q.push(que {temp.n+l*100+i,temp.step+1});
                   viss[temp.n+l*100+i]=1;
               }

        temp=q.front();
        temp.n=temp.n/10;
        for(int i=0; i<=9; i++)
            if(!viss[temp.n*10+i]&&v[temp.n*10+i])
                {
                    q.push(que {temp.n*10+i,temp.step+1});
                    viss[temp.n*10+i]=1;
                }

        q.pop();
    }
    return -1;
}

int main()
{
    primelist();
    int T;
    cin >> T;
    while(T--)
    {
        memset(viss,0,sizeof(viss));
        int s,e;
        cin >> s >> e;
        cout << bfs(s,e) << endl;
    }
    return 0;
}
