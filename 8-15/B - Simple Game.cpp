#include <iostream>
using namespace std;

int main()
{
   int n,m,a;
   cin >> n >> m;
   if(n==1)
    {
        cout << "1";
        return 0;
    }

   if(m>double(n)*1.0/2)
    cout << m-1;
   else
    cout << m+1 << endl;
    return 0;
}
