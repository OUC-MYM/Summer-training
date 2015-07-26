#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

char tostr[1000010];
int len;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> tostr;

        len=strlen(tostr);

        if(tostr[0]!='M')
        {
            cout << "No" << endl;
            continue;
        }

        int tot=0;int ok=1;
        for(int i=1; i<len; i++)
        {
            if(tostr[i]=='M')
            {
                cout << "No" << endl;
                ok=0;
                break;
            }
            if(tostr[i]=='U')
                tot=tot+3;
            else
                tot++;
        }

        if(!ok)
            continue;

        if(tot==1||tot%2==0&&tot%3!=0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    return 0;
}
