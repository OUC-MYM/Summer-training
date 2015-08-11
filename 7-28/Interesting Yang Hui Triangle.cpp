#include <iostream>
#include <cstdio>
using namespace std;

int N,P;

int main()
{
    int T=0;
    while(cin >> P >> N && (N||P))
    {
        int sum=1;
        for(int i=N; i>0; i=i/P)
            sum=sum*(i%P+1);
        printf("Case %d: %04d\n",++T,sum%10000);
    }
    return 0;
}
