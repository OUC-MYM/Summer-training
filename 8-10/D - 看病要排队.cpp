#include <iostream>
#include <algorithm>
using namespace std;

struct P
{
    int x;
    int id;
};

bool cmp(P a,P b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    return a.id<b.id;
}

int N;

int main()
{
    P A[2020],B[2020],C[2020];
    while(cin >> N)
    {
        int cnt1,cnt2,cnt3;
        cnt1=cnt2=cnt3=0;

        int _ID=1;

        char temp[20];
        for(int i=1; i<=N; i++)
        {
            cin >> temp;
            if(temp[0]=='I')
            {
                int a,b;
                cin >> a >> b;
                if(a==1)
                    A[cnt1].x=b,A[cnt1++].id=_ID++;
                if(a==2)
                    B[cnt2].x=b,B[cnt2++].id=_ID++;
                if(a==3)
                    C[cnt3].x=b,C[cnt3++].id=_ID++;
            }
            if(temp[0]=='O')
            {
                int a;
                cin >> a;
                if(a==1)
                {
                    sort(A,A+cnt1,cmp);
                    (A[0].x==-1||A[0].id==0)?(cout << "EMPTY" << endl ):( cout << A[0].id << endl);
                    A[0].x=-1;
                }
                 if(a==2)
                {
                    sort(B,B+cnt2,cmp);
                    (B[0].x==-1||B[0].id==0)?(cout << "EMPTY" << endl ):( cout << B[0].id << endl);
                    B[0].x=-1;
                }
                 if(a==3)
                {
                    sort(C,C+cnt3,cmp);
                    (C[0].x==-1||C[0].id==0)?(cout << "EMPTY" << endl ):( cout << C[0].id << endl);
                    C[0].x=-1;
                }
            }
        }
    }
    return 0;
}
