#include <iostream>
#include <cstdio>
using namespace std;

int year;
int A,B;
int monday[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

int gcd(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}


int main()
{
    int T;
    cin >> T;
    int N;
    N=0;
    int tot;
    int mon,day;
    while(T--)
    {
        ++N;
        tot=0;
        cin >> A >> B >> year;

        if(year%100!=0&&year%4==0||year%400==0)
        {
            int temp=gcd(2,29);
                if(temp==A)
                {
                    if(2*29/temp==B)
                    {
                        tot++;
                        mon=2;
                        day=29;
                    }
                }

        }

        for(int i=1; i<=12; i++)
        {
            if(tot>=2)
                break;
            for(int j=1; j<=monday[i]; j++)
            {
                if(tot>=2)
                    break;
                int temp=gcd(i,j);
                if(temp==A)
                {
                    if(i*j/temp==B)
                    {
                        tot++;
                        mon=i;
                        day=j;
                    }
                }
            }
        }

        if(tot==1)
            {
                cout << "Case #" << N << ": " << year << "/";
                if(mon<10)
                    cout << "0" << mon << "/";
                else
                    cout << mon << "/";
                if(day<10)
                    cout << "0" << day << endl;
                else
                    cout << day << endl;
            }
        if(tot>=2)
            printf("Case #%d: 1\n",N);
        if(tot==0)
           printf("Case #%d: -1\n",N);
    }
    return 0;
}
