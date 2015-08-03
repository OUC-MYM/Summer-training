#include <iostream>
#include <cstring>
using namespace std;

bool num[1000010];

void solv()
{
    for(int i=1; i<1000000; i++)
    {
        int temp=i;
        int flag=0;
        while(temp)
        {
            int yu=temp%10;
            if(yu==4)
            {
                num[i]=true;
                break;
            }
            if(yu==6&&flag)
            {
                num[i]=true;
                break;
            }
            if(yu==2)
                flag=1;
            else
                flag=0;
            temp=temp/10;
        }
    }
}

int n,m;

int main()
{
    memset(num,0,sizeof(num));
    solv();
    while(cin >> n >> m &&(n||m))
    {
        int cnt=m-n+1;
        for(int i=n; i<=m; i++)
            if(num[i])
                cnt--;
        cout << cnt << endl;
    }
    return 0;
}
