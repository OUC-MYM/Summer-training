#include <iostream>
#include<cstring>
using namespace std;

char a[100000000],b[100000000];

int main()
{

    while(cin >> a >> b)
    {
        int i,j;


        if(a[0]=='-'||b[0]=='-')
        {
            if(a[0]!=b[0])
            {
                cout << "NO" << endl;
                continue;
            }
        }
        int lena=strlen(a),lenb=strlen(b);

        if(a[0]=='-'&&b[0]=='-')
        {
            for(i=1; a[i]=='0'; i++)
                ;
            for(j=1; b[j]=='0'; j++)
                ;
        }
        else
        {
            for(i=0; a[i]=='0'; i++)
                ;
            for(j=0; b[j]=='0'; j++)
                ;
        }

        int ok=1,flag=0;

        for( ; i<lena&&j<lenb ; i++,j++)
        {
            if(a[i]!=b[j])
            {
                cout << "NO" << endl;
                ok=0;
                break;
            }
            if(a[i]=='.'||b[j]=='.')
            {
                flag=1;
                if(a[i]!=b[i])
                {
                    cout << "NO" << endl;
                    ok=0;
                    break;
                }
            }
        }
        if(!ok)
            continue;

        if(flag)
        {
            for( ; i<lena; i++)
                if(a[i]!='0')
                {
                    //cout << "NO" << endl;
                    ok=0;
                    break;
                }
            for( ; j<lenb; j++)
                if(b[j]!='0')
                {
                    //cout << "NO" << endl;
                    ok=0;
                    break;
                }
            if(!ok)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            continue;

        }
        else
        {
            if(i!=lena)
            {
                if(a[i]!='.')
                {
                    //cout << "NO" << endl;
                    ok=0;
                }
                else
                {
                    for(++i; i<lena; i++)
                        if(a[i]!='0')
                        {
                            //cout << "NO" << endl;
                            ok=0;
                            break;
                        }
                }
            }
            if(j!=lenb)
            {
                if(b[j]!='.')
                {
                    //cout << "NO" << endl;
                    ok=0;
                }
                else
                {
                    for(++j; j<lenb; j++)
                        if(b[j]!='0')
                        {
                            //cout << "NO" << endl;
                            ok=0;
                            break;
                        }
                }
            }
            if(!ok)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            continue;
        }

    }
    return 0;
}

/*
0.1  000.1
-0000.1  -00.1
-0.1  0.1
0.01  0.001
0.10  0.100
100.00   100.000001
100   100.0000
100   1000.00
0100    100.00
0100 100.01
*/
