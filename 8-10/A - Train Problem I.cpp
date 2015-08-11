#include <iostream>
#include <map>
using namespace std;

int N;

int main()
{
    while(cin >> N)
    {
        map <int,string>ans;
        string a,b;
        cin >> a >> b;
        int len=a.length();
        char Stack[20];
        int top=0;
        int p1,p2;
        p1=p2=0;
        int cnt=0;
        while(p1<len)
        {
            Stack[++top]=a[p1++];
            ans[cnt++]="in";
            while(top&&Stack[top]==b[p2])
                p2++,top--,ans[cnt++]="out";
        }
        if(!top)
        {
            cout << "Yes." << endl;
            for(int i=0; i<cnt; i++)
                cout << ans[i] << endl;
        }
        else
            cout << "No." << endl;
            cout << "FINISH" << endl;
        }
    return 0;
}
