#include <iostream>

using namespace std;

char str[1010];

int main()
{
    while(cin >> str)
    {
        int ans=0;
        for(int i=0; str[i]!='B'; i++)
            if(str[i]=='(')
                ans++;
            else
                ans--;
        cout << ans << endl;
    }
    return 0;
}
