#include<iostream>
#define MAX 10000000
using namespace std;

int N,C;

int prime[MAX];
int num=2;
int v[MAX];
int vis[MAX];
void primelist()
{
    for(int i=2; i*i<MAX; i++)
        if(!v[i])
        {
            vis[i]=1;
            prime[num++]=i;
            for(int j=2*i; j*j<MAX; j=j+i)
                v[j]=1;
        }
}

int main()
{
    primelist();
    prime[1]=1;
    vis[1]=1;
    while(cin >> N >> C)
    {
        int temp1,temp2;
        int cnt=0;
        for(int i=1; i<=N; i++)
            if(vis[i])
                cnt++;
        //cout << cnt << endl;

        if(cnt%2)
        {
            temp1=cnt/2+1;
            temp2=temp1;
        }
        else
        {
            temp1=cnt/2;
            temp2=temp1+1;
        }
        //cout << temp1 << " " << temp2 << endl;

        for(int i=0; i<C-1&&temp1>=1; temp1--,temp2++,i++)
            ;
        if(temp1==0)
        {
            temp1++;
            temp2--;
        }
        //cout << temp1 << "|" << temp2 << endl;

        cout << N << " " << C << ":";
        for(int i=temp1; i<=temp2; i++)
            cout << " " << prime[i];
        cout << endl << endl;
    }
    return 0;
}
