#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.1415926
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        double P=0;
        double x1,y1,x2,y2;
        double temp1,temp2,temp3,temp4;
        double ansx,ansy;
        x1=y1=0;
        x2=y2=1;

        int n;
        cin >> n;
        while(n--)
        {
            double x,y,p;
            cin >> x >> y >> p;
            P=P+p;
            temp1=x+(x1-x)*cos(p)-(y1-y)*sin(p);
            temp2=y+(x1-x)*sin(p)+(y1-y)*cos(p);
            temp3=x+(x2-x)*cos(p)-(y2-y)*sin(p);
            temp4=y+(x2-x)*sin(p)+(y2-y)*cos(p);
            x1=temp1;
            y1=temp2;
            x2=temp3;
            y2=temp4;
        }

        while(P>=2*PI)
            P=P-2*PI;

        ansx=((x1*x1+y1*y1)*(2*y2-2)-(x2*x2+y2*y2)*2*y1+4*y1)/(-4*x1-4*x2*y1+4*x1*y2+4*y1);
        ansy=((x1*x1+y1*y1)-2*ansx*x1)/(2*y1);
        printf("%.10lf %.10lf %.10lf\n",ansx,ansy,P);
    }
    return 0;
}
