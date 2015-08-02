#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int vis[70000];
int ans[70000];
int change[]= {63624,62532,61986,61713,36744,20292,12066,7953,35064,17652,8946,4593,34959,17487,8751,4383};

struct point
{
    int num;
    int step;
};

void bfs(int n)
{
    queue<point>q;
    q.push(point {n,0});
    vis[n]=1;

    while(!q.empty())
    {
        point temp1=q.front();
        point temp2;
        q.pop();

        for(int i=0; i<16; i++)
        {
            temp2.num=temp1.num^change[i];
            if(vis[temp2.num]==0)
            {
                ans[temp2.num]=i;
                temp2.step=temp1.step+1;
                vis[temp2.num]=1;
                q.push(temp2);
            }
            if(temp2.num==0)
            {
                cout << temp1.step+1 << endl;
                int i=0;
                while(i!=n)
                {
                    printf("%d %d\n",ans[i]/4+1,ans[i]%4+1);
                    i=i^change[ans[i]];
                }
                return;
            }
        }
    }
    return;
}

int main()
{
    char ch;
    int num=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            cin >> ch;
            if(ch=='+')
                num=num*2+1;
            if(ch=='-')
                num=num*2;
        }
    if(num==0)
        cout << "0" << endl;
    bfs(num);
    return 0;
}
