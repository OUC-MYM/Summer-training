#include <iostream>

using namespace std;

string URL[120];
int tot;

int main()
{
    char cmd[25];
    int p=0;
    tot=p;
    URL[0]="http://www.acm.org/";
    while(cin >> cmd && cmd[0]!='Q')
    {
        if(cmd[0]=='V')
        {
            cin >> URL[++p];
            cout << URL[p] <<endl;
            tot=p;
            continue;
        }

        if(cmd[0]=='B')
        {
            if(p==0)
            {
                cout << "Ignored" << endl;
                continue;
            }
            p--;
            cout << URL[p] <<endl;
        }

        if(cmd[0]=='F')
        {
            if(p==tot)
            {
                cout << "Ignored" << endl;
                continue;
            }
            p++;
            cout << URL[p] <<endl;
        }
    }
    return 0;
}
