#include <iostream>
#include <queue>
using namespace std;

int vis[70000];

struct p
{
    int num;
    int step;
};

int bfs(int n)
{
    queue<p>q;
    q.push(p {n,0});
    vis[n]=1;
    p temp;
    while(!q.empty())
    {
        temp=q.front();
        temp.num=temp.num^(1<<0);
        temp.num=temp.num^(1<<1);
        temp.num=temp.num^(1<<4);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<0);
        temp.num=temp.num^(1<<1);
        temp.num=temp.num^(1<<2);
        temp.num=temp.num^(1<<5);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<1);
        temp.num=temp.num^(1<<2);
        temp.num=temp.num^(1<<3);
        temp.num=temp.num^(1<<6);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<3);
        temp.num=temp.num^(1<<2);
        temp.num=temp.num^(1<<7);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<4);
        temp.num=temp.num^(1<<0);
        temp.num=temp.num^(1<<5);
        temp.num=temp.num^(1<<8);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<5);
        temp.num=temp.num^(1<<1);
        temp.num=temp.num^(1<<4);
        temp.num=temp.num^(1<<6);
        temp.num=temp.num^(1<<9);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<6);
        temp.num=temp.num^(1<<2);
        temp.num=temp.num^(1<<5);
        temp.num=temp.num^(1<<7);
        temp.num=temp.num^(1<<10);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<7);
        temp.num=temp.num^(1<<3);
        temp.num=temp.num^(1<<6);
        temp.num=temp.num^(1<<11);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<8);
        temp.num=temp.num^(1<<4);
        temp.num=temp.num^(1<<9);
        temp.num=temp.num^(1<<12);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<9);
        temp.num=temp.num^(1<<5);
        temp.num=temp.num^(1<<8);
        temp.num=temp.num^(1<<10);
        temp.num=temp.num^(1<<13);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<10);
        temp.num=temp.num^(1<<11);
        temp.num=temp.num^(1<<6);
        temp.num=temp.num^(1<<9);
        temp.num=temp.num^(1<<14);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<11);
        temp.num=temp.num^(1<<7);
        temp.num=temp.num^(1<<15);
        temp.num=temp.num^(1<<10);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<12);
        temp.num=temp.num^(1<<8);
        temp.num=temp.num^(1<<13);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<13);
        temp.num=temp.num^(1<<14);
        temp.num=temp.num^(1<<12);
        temp.num=temp.num^(1<<9);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<14);
        temp.num=temp.num^(1<<15);
        temp.num=temp.num^(1<<10);
        temp.num=temp.num^(1<<13);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        temp=q.front();
        temp.num=temp.num^(1<<15);
        temp.num=temp.num^(1<<11);
        temp.num=temp.num^(1<<14);
        if(temp.num==0||temp.num==65535)
            return temp.step+1;
        if(!vis[temp.num])
        {
            vis[temp.num]=1;
            q.push(p {temp.num,temp.step+1});
        }

        q.pop();
    }
    return -1;
}

int main()
{
    char ch;
    int num=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            cin >> ch;
            if(ch=='b')
                num=num*2+1;
            if(ch=='w')
                num=num*2;
        }
    if(num==0||num==65535)
        cout << "0" << endl;
    else
    {
        int temp=bfs(num);
        if(temp==-1)
            cout << "Impossible" << endl;
        else
            cout << temp << endl;
    }

}
