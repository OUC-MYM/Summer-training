#include<iostream>
#define MAX 10000000
using namespace std;

int vis[16010];
int v[16010];
void primelist()
{
    for(int i=2; i<=16000; i++)
        if(!v[i])
        {
            vis[i]=1;
            for(int j=2*i; j<=16000; j=j+i)
                v[j]=1;
        }
}

int main()
{
    primelist();
    vis[1]=0;
    vis[2]=0;

    int n;
    int N=0;
    while(cin >> n && n>0)
    {
        N++;
        cout << N << ": ";
        cout << (vis[n] ? "yes":"no") << endl;
    }
    return 0;
}
