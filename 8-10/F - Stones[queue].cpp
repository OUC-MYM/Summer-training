#include <iostream>
#include <queue>

using namespace std;

struct p
{
    int pos;
    int add;
    friend bool operator <(p a,p b)
    {
        if(a.pos!=b.pos)
            return a.pos>b.pos;
        return a.add>b.add;
    }
};

int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin >>T;
    while(T--)
    {
        priority_queue <p> q;
        p temp;

        int N;
        cin >> N;
        int MAX=0;
        while(N--)
        {
            cin >> temp.pos >> temp.add;
            MAX=max(MAX,temp.pos);
            q.push(temp);
        }

        int cnt=1;

        while(!q.empty())
        {
            if(cnt%2)
            {
                temp=q.top();
                q.pop();
                temp.pos=temp.pos+temp.add;
                MAX=max(MAX,temp.pos);
                q.push(temp);
            }
            else
                q.pop();
            cnt++;
        }
        cout << MAX << endl;
    }
    return 0;
}
