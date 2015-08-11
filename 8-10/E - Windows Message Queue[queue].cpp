#include <iostream>
#include <queue>
using namespace std;

struct p
{
    string msg;
    int par;
    int pro;
    int id;
    friend bool operator <(p a,p b)
    {
        if(a.pro!=b.pro)
            return a.pro>b.pro;
        return a.id>b.id;
    }
};



int main()
{
    cin.sync_with_stdio(false);
    char cmd[25];

    priority_queue <p> q;
    int cnt=0;

    while(cin >> cmd)
    {
        if(cmd[0]=='P')
        {
            p temp;
            cin >> temp.msg >> temp.par >> temp.pro;
            temp.id=cnt++;
            q.push(temp);
        }
        if(cmd[0]=='G')
        {
            if(!q.empty())
            {
                p temp=q.top();
                q.pop();
                cout << temp.msg << " " << temp.par << endl;
            }
            else
                cout << "EMPTY QUEUE!" << endl;
        }
    }
    return 0;
}
