#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#define PI 3.1415926
#define INF 1<<30

#include <fstream>
using namespace std;

int main()
{
    int T;
    cout << "�������Զ�����.cpp�ļ�" << endl;
    cout << "������д��ĸ��˳���Զ��������26���ļ�" << endl;
    cout << "������Ҫ�������ļ�������";
    while(1)
    {
        cin >> T;
        if(T<1||T>26)
            cout << "������1-26������: " ;
        else
            break;
    }
    char name[25]=" .cpp";
    for(char i='A'; i<'A'+T; i++)
    {
        name[0]=i;
        ofstream file(name);
        if(file)
            cout << "�ɹ����� " << name << " �ļ�" << endl;
        file << "#include <iostream>" << endl;
        file << "#include <cstdio>" << endl;
        file << "#include <cstring>" << endl;
        file << "#include <algorithm>" << endl;
        file << "#include <cmath>" << endl;
        file << "#include <map>" << endl;
        file << "#include <queue>" << endl;
        file << "#include <stack>" << endl;
        file << "#include <vector>" << endl;
        file << "#include <set>" << endl;
        file << "#define PI 3.1415926" << endl;
        file << "#define INF 1<<30" << endl;
        file << "using namespace std;" << endl << endl << endl;
        file << "int main()" << endl;
        file << "{" << endl;
        file << "   cin.sync_with_stdio(false);" << endl;
        file << "   int T;" << endl;
        file << "   cin >> T;" << endl;
        file << "   while(T--)" << endl;
        file << "   {" << endl << endl;
        file << "   }" << endl;
        file << "   return 0;" << endl;
        file << "}" << endl;
    }
    cout << "����5����Զ��˳�" << endl;
    for(long long i=1;i<2000000000;i++)
        ;
    return 0;
}
