#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    string a,b;

    map<string, string> word;
    while(m--)
    {
        cin >> a >> b;
        if(a.length()>b.length())
            word[a]=b;
        else
            word[a]=a;
    }

    for(int i=0; i<n-1; i++)
    {
        string temp;
        cin >> temp;
        cout << word[temp] << " ";
    }

    string temp;
    cin >> temp;
    cout << word[temp] <<endl;

    return 0;
}
