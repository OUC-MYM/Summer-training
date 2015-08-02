#include <iostream>
#include <cstring>
using namespace std;

int ok;


void slov(char a[],char b[])
{
    if(strcmp(a,b)==0)
        return;

    int len=strlen(a);

    if(len==1)
        if(strcmp(a,b)!=0)
        {
            ok=0;
            return;
        }

    if(len%2)
    {
        ok=0;
        return;
    }
    else
    {
        char a1[len],a2[len],b1[len],b2[len];
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        for(int i=0; i<len/2; i++)
            a1[i]=a[i],b1[i]=b[i];
        for(int i=len/2; i<len; i++)
            a2[i-len/2]=a[i],b2[i-len/2]=b[i];
        //cout << a1 <<endl<< a2 << endl<<b1 << endl << b2 << endl;
        slov(a1,b2);
        if(ok)
            slov(a2,b1);
        if(!ok)
        {
            ok=1;
            slov(a1,b1);
            if(ok)
                slov(a2,b2);
        }
    }
}

int main()
{
    char a[200010],b[200010];
    while(cin >> a >> b)
    {
        ok=1;
        slov(a,b);
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
