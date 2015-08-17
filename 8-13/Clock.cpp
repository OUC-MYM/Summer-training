#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int GCD(int a,int b)
{
    return (b>0)?GCD(b,a%b):a;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int hh,mm,ss;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        if(hh>=12)
            hh=hh-12;
        int fenzia,fenzib,fenzic,fenmu;
        fenmu=60*60*12;
        fenzia=(hh*60*60+mm*60+ss)*360;
        fenzib=(mm*60+ss)*12*360;
        fenzic=ss*60*12*360;
        {
            int temp=abs(fenzia-fenzib);
            if(temp>60*60*6*360)
                temp=60*60*360*12-temp;
            int temp2=fenmu;
            int gcd=GCD(temp,temp2);
            if(temp2==gcd)
                cout << temp/gcd << " ";
            else
                cout << temp/gcd << "/" << temp2/gcd << " ";
        }

        {
            int temp=abs(fenzia-fenzic);
            if(temp>60*60*6*360)
                temp=60*60*360*12-temp;
            int temp2=fenmu;
            int gcd=GCD(temp,temp2);
            if(temp2==gcd)
                cout << temp/gcd << " ";
            else
                cout << temp/gcd << "/" << temp2/gcd << " ";
        }

        {
            int temp=abs(fenzib-fenzic);
            if(temp>60*60*6*360)
                temp=60*60*360*12-temp;
            int temp2=fenmu;
            int gcd=GCD(temp,temp2);
            if(temp2==gcd)
                cout << temp/gcd << " " << endl;
            else
                cout << temp/gcd << "/" << temp2/gcd << " " << endl;
        }
    }
    return 0;
}
