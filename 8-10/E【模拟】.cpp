#include <iostream>
#include <queue>
using namespace std;

struct p
{
    string msg;
    int par;
    int pro;
    int id;
};

int main()
{
    char cmd[25];

    int cnt=0;

    queue <p> q;
    queue <p> tmp;

    while(cin >> cmd)
    {
        if(cmd[0]=='P')
        {
            p temp;
            cin >> temp.msg >> temp.par >> temp.pro;
            temp.id=++cnt;
            while(!q.empty())
            {
                p temp1=q.front();
                if(temp1.pro<=temp.pro&&temp1.id<temp.id)
                {
                    q.pop();
                    tmp.push(temp1);
                }
                else
                    break;
            }
            tmp.push(temp);
            while(!q.empty())
            {
                p temp1=q.front();
                q.pop();
                tmp.push(temp1);
            }
            q=tmp;
            while(!tmp.empty())
                tmp.pop();
        }
        if(cmd[0]=='G')
        {
            if(!q.empty())
            {
                p temp1=q.front();
                q.pop();
                cout << temp1.msg << " " << temp1.par << endl;
            }
            else
                cout << "EMPTY QUEUE!" << endl;
        }
    }
    return 0;
}
