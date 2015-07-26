#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char strbug[10];
int isnum[256];


int tonumb(string temp)
{
    int n=0;
    for(int i=0; i<7; i++)
        if(temp[i]=='-')
            n=n*2;
        else
            n=n*2+1;
    return n;
}

struct LED
{
    int pos;
    string led;
};

int bfs(string n)
{
    int tot=0;

    queue <LED> q;

    q.push(LED {0,"-------"});

    if(isnum[tonumb("-------")|tonumb(n)])
        tot++;

    LED temp;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        for(int i=temp.pos; i<7; i++)
            if(strbug[i]!='-')
            {
                temp.led[i]='X';
                if(isnum[tonumb(temp.led)|tonumb(n)])
                {
                    tot++;
                    //cout << "tot" << temp.led << ">>" << endl;
                }
                q.push(LED {i+1,temp.led});
                temp.led[i]='-';
            }
    }
    return tot;
}

int main()
{
    isnum[119]=1;
    isnum[18]=1;
    isnum[93]=1;
    isnum[91]=1;
    isnum[58]=1;
    isnum[107]=1;
    isnum[111]=1;
    isnum[82]=1;
    isnum[127]=1;
    isnum[123]=1;

    int ans;
    char led[10];

    int T=0;
    while(++T)
    {
        int N;
        cin >> N;
        if(N==-1)
            break;

        cin >> strbug;

        ans=1;
        for(int i=0; i<N; i++)
        {
            cin >> led;
            ans=ans*bfs(led);
        }

        cout << "Case "<<T<<": " << ans << endl;
    }
    return 0;
}

/*
2
-b-d---
--c--f-
--c--f-
*/

