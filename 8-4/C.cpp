#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        char str[110];
        cin >> str;
        int len=strlen(str);
        int cnt1=0;
        int cnt2=0;
        int shift=0;
        int lock=0;
        int flag=0;

        for(int i=0; i<len; i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                if(!flag)
                {
                    cnt1++;
                    if(cnt1==2)
                    {
                        flag=1;
                        lock++;
                        cnt1=0;
                    }
                }
                if(flag&&cnt2>0&&cnt2<2)
                {
                    shift=shift+cnt2;
                    cnt2=0;
                }
            }
            if(str[i]>='a'&&str[i]<='z')
            {
                if(flag)
                {
                    cnt2++;
                    if(cnt2==2)
                    {
                        flag=0;
                        cnt2=0;
                    }
                }
                if(!flag&&cnt1>0&&cnt1<2)
                {
                    shift=shift+cnt1;
                    cnt1=0;
                }
            }
        }
        if(!flag&&cnt1==1)
            shift++;

        cout << len+shift+lock*2 << endl;
        // cout << len <<"+" << shift <<"+" << lock << endl;
    }
    return 0;
}

/*
Pirates
HDUacm
HDUACM
aaaaAaaaa
aaaAAaaaa
aaaAAAaaa
AAAAaAAAA
AAAaaaAAA
AAAaaAAAA
AAAAAAAAa
*/
