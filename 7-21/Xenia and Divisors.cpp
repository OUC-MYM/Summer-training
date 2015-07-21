#include <iostream>
using namespace std;

int num[100009];
int sum[10];

int main()
{
    int n;
    cin >> n;
    int ok=1;
    for(int i=0; i<n;i++)
    {
        cin >> num[i];
        if(num[i]==5||num[i]==7)
            ok=0;
        sum[num[i]]++;
    }
    if(ok==0)
    {
        cout << "-1" << endl;
        return 0;
    }
    if(sum[1]!=n/3)
    {
        cout << "-1" << endl;
        return 0;
    }

    if(sum[4]!=0&&sum[2]>=sum[4])
    {
        if(sum[2]==sum[4]&&sum[3]==sum[6])
        {
            for(int i=0; i<sum[2]; i++)
                cout << "1 2 4" << endl;
            for(int i=0; i<sum[3]; i++)
                cout << "1 3 6" << endl;
        }
        else if(sum[2]>sum[4])
        {
            sum[2]=sum[2]-sum[4];
            if(sum[6]==n/3-sum[4]&&sum[2]+sum[3]+sum[4]==n/3)
            {
                for(int i=0; i<sum[4]; i++)
                    cout << "1 2 4" << endl;
                for(int i=0; i<sum[2]; i++)
                    cout << "1 2 6" << endl;
                for(int i=0; i<sum[3]; i++)
                    cout << "1 3 6" << endl;
            }
            else
                cout << "-1" << endl;
        }
        else
            cout << "-1" << endl;
    }
    else
    {
        if(sum[6]==n/3&&sum[2]+sum[3]==n/3)
        {
            for(int i=0; i<sum[2]; i++)
                cout << "1 2 6" << endl;
            for(int i=0; i<sum[3]; i++)
                cout << "1 3 6" << endl;
        }
        else
            cout << "-1" << endl;
    }


    return 0;
}


/*
1 2 4
1 2 6
1 3 6
*/

