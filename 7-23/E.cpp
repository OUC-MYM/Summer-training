#include <iostream>
#include <cmath>
using namespace std;

int s,e;
double num[1000010];
int ok=0;
int ans;

void slov(int s,int e)
{
    for(int i=e; i>=s; i--)
    {
        int k=sqrt(i);
        for(int j=1; j<=k; j++)
        {
            if(i%j==0)
            {
                if(j*j == i)
                    num[i]=num[i]+j;
                else
                    num[i]=num[i]+j+i/j;
            }
        }

        if(num[i]-i==1)
        {
            ok=1;
            ans=i;
            return;
        }
        num[i]=(num[i]-i)*1.0/i;
    }
}

int main()
{
    cin >> s >> e;

    if(s==1)
    {
        cout << "1" << endl;
        return 0;
    }

    slov(s,e);

    if(ok)
    {
        cout << ans << endl;
        return 0;
    }

    double temp=999999;

    for(int i=s; i<=e; i++)
    {
        if(temp>num[i])
        {
            temp=num[i];
            ans=i;
        }
    }

    cout << ans << endl;
    return 0;
}
