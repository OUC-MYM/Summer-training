#include<iostream>
#include<queue>
using namespace std;

int step[200005];
queue<int> q;

int main()
{
    int N,K;
    cin >> N >> K;

    q.push(N);
    while(!q.empty())
    {
       int temp=q.front();
       q.pop();
       if(temp==K)
        break;

       if(step[temp+1]==0&&temp<K)
       {
           q.push(temp+1);
           step[temp+1]=step[temp]+1;
       }

       if(step[temp-1]==0&&temp>0)
       {
          q.push(temp-1);
           step[temp-1]=step[temp]+1;
       }

       if(step[temp*2]==0 && temp<=K)
       {
           q.push(temp*2);
           step[temp*2]=step[temp]+1;
       }
    }
    cout << step[K] << endl;
    return 0;
}
