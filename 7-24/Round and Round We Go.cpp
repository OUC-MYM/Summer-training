#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[80];
int len;
char toch[80];
int ok;

bool bigmul(int i)
{
    int yu=0;
    for(int j=len-1; j>=0; j--)
    {
        int temp=i*(num[j]-'0')+yu;
        yu=temp/10;
        toch[j]=temp%10+'0';
    }
    cout << toch << endl;
    if(yu/10>0)
    {
        return false;
    }
    return true;
}

bool ifcircle()
{
    int ok=0;
    for(int j=0; j<len; j++)
        if(toch[j]==num[0])
        {
            ok=1;
            for(int t=j; t<j+len; t++)
                    if(toch[t%len]!=num[t-j])
                        ok=0;
            if(ok)
                return true;
        }
    if(!ok)
        return false;
    return true;
}

int main()
{
    while (cin>>num)
    {
        ok=1;
        len=strlen(num);
        for(int i=2; i<=len; i++)
        {
            if(!bigmul(i))
            {
                ok=0;
                break;
            }
            if(!ifcircle())
            {
                ok=0;
                break;
            }
        }
        if(ok)
            printf("%s is cyclic\n",num);
        else
            printf("%s is not cyclic\n",num);
    }
}
