#include <iostream>
#include <cstdio>
using namespace std;

int p,e,i,d;
int Mi[100];
int mi[100];
int t[100];
int a[100];

int exGCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exGCD(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int main()
{
    int N=0;
    int x,y;
    while(cin >> p >> e >> i >> d)
    {
        N++;
        if(p==-1&&e==-1&&i==-1&&d==-1)
            break;

        mi[1]=23;
        a[1]=p%23;
        mi[2]=28;
        a[2]=e%28;
        mi[3]=33;
        a[3]=i%33;

        Mi[1]=28*33;
        Mi[2]=23*33;
        Mi[3]=23*28;

        int ans=0;
        for(int j=1; j<=3; j++)
        {
            int gcd=exGCD(Mi[j],mi[j],x,y);
            t[j]=x;
            ans=ans+a[j]*t[j]*Mi[j];
        }
        ans=ans%(28*33*23);
        while(ans<=d)
            ans=ans+28*33*23;

            printf("Case %d: the next triple peak occurs in %d days.\n",N,ans-d);
    }
    return 0;
}
