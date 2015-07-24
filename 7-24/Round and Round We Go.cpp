#include <iostream>
#include <cstring>
using namespace std;

char str[80];
char temp[80];
int len;
int ok;

void cyclic(char ch[])
{
    ch[79]=ch[0];
    for(int i=0; i<len-1; i++)
        ch[i]=ch[i+1];
    ch[len-1]=ch[79];
}

void check(char ch[])
{
    char n[80];

    for(int k=2; k<=n[0]-'0'; k++)
    {
        if(!ok)
            break;
        strcpy(n,ch);

        int yu=n[0]-'0'-k;

        for(int i=1; i<len; i++)
        {
            int temp=n[i]+yu*10;
            yu=temp%k;
        }
        if(yu!=0)
            ok=0;
    }
}

int main()
{
    while(cin >> str)
    {
        len=strlen(str);
        ok=1;

        strcpy(temp,str);

        for(int i=0; i<len; i++)
        {
            if(!ok)
                break;
            cyclic(str);
            cout << str << endl;
            check(str);
        }

        if(!ok)
            cout << temp << " is not cyclic" << endl;
        else
            cout << temp << " is cyclic" << endl;

    }
    return 0;
}
