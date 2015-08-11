#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A,B;
        cin >> A >> B;
        int sumA=0,sumB=0;
        for(int i=1; i*i<=A; i++)
            if(A%i==0)
            {
                sumA=sumA+i;
                if(i*i!=A)
                    sumA=sumA+A/i;
            }
        sumA=sumA-A;

        for(int i=1; i*i<=B; i++)
            if(B%i==0)
            {
                sumB=sumB+i;
                if(i*i!=A)
                    sumB=sumB+B/i;
            }
        sumB=sumB-B;

        if(sumA==B&&sumB==A)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
