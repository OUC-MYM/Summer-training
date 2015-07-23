#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double value[100100];

int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
        scanf("%lf",&value[i]);


    int p1=0,p2=1;
    double inclination=0;
    for(int i=2; i<=N; i++)
    {
        double temp = value[i] - value[i-1];
        if(temp<0)
            temp=-1*temp;
        if(inclination<temp)
        {
            p1=i-1;
            p2=i;
            inclination = temp;
        }
    }
    printf("%d %d\n",p1,p2);

    return 0;
}
