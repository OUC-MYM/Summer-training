#include <iostream>

using namespace std;

int main()
{
    int n;
    int x;
    int p=1;
    int time=0;
    int a,b;
    cin >> n >> x;
    while(n--)
    {
        cin >> a >> b;
        while(p+x<=a)
            p=p+x;
        //cout << p;
        time = time + (b-a+1) + (a-p);
        p=b+1;
    }
    cout << time << endl;
}
