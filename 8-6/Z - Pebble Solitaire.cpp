#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int cnt;


struct point
{
    string b;
    int tot;
};

int bfs(string str)
{

    map<string,int> vis;
    int ans=0;
    queue <point> q;
    q.push(point {str,0});
    while(!q.empty())
    {
        point temp1,temp2;
        temp1=q.front();
        q.pop();

        for(int i=0; i<10; i++)
        {
            if(temp1.b[i]=='o'&&temp1.b[i+1]=='o'&&temp1.b[i+2]=='-')
            {
                temp2=temp1;
                temp2.b[i]='-',temp2.b[i+1]='-',temp2.b[i+2]='o';
                if(!vis[temp2.b])
                {
                    vis[temp2.b]=1;
                    temp2.tot++;
                    ans=max(ans,temp2.tot);
                    q.push(temp2);
                }
            }
            if(temp1.b[i]=='-'&&temp1.b[i+1]=='o'&&temp1.b[i+2]=='o')
            {
                temp2=temp1;
                temp2.b[i]='o',temp2.b[i+1]='-',temp2.b[i+2]='-';
                if(!vis[temp2.b])
                {
                    vis[temp2.b]=1;
                    temp2.tot++;
                    ans=max(ans,temp2.tot);
                    q.push(temp2);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string str;
        cin >> str;
        cnt=0;
        for(int i=0; i<12; i++)
            if(str[i]=='o')
                cnt++;
        cout << cnt-bfs(str) << endl;
    }
    return 0;
}
