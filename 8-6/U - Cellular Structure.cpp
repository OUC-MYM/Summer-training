#include <iostream>

using namespace std;

string str;
int len;

int dfs(int s,int e)
{
    if(s==e&&str[s]=='A')
        return 1;
    if(str[e]=='A'&&dfs(s,e-1))
        return 1;
    if(str[e]=='B'&&str[e-1]=='A'&&dfs(s,e-2))
        return 2;
    if(e-s>1&&str[s]=='B'&&str[e]=='A'&&dfs(s+1,e-1))
        return 3;
    return 0;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> str;
        len=str.length();

        int ok=1;

        if(len==1&&str[0]=='A')
        {
            cout << "SIMPLE" << endl;
            continue;
        }

        int temp=dfs(0,len-1);
        switch(temp)
        {
        case 1:
            cout << "SIMPLE" << endl;
            break;
        case 2:
            cout << "FULLY-GROWN" << endl;
            break;
        case 3:
            cout << "MUTAGENIC" << endl;
            break;
        case 0:
            cout << "MUTANT" << endl;
            break;
        }
    }
    return 0;
}
