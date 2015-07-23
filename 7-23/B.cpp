#include <iostream>
#include <algorithm>
using namespace std;

char dir;

struct point
{
    char color;
    char  ace;
};

int to(char dir)
{
    if(dir=='N')
        return 0;
    if(dir=='E')
        return 1;
    if(dir=='S')
        return 2;
    return 3;
}

int toco(char ch)
{
    if(ch=='C')
        return 1;
    if(ch=='D')
        return 2;
    if(ch=='S')
        return 3;
    return 4;
}

int toace(char ch)
{
    if(ch=='2')
        return 2;
    if(ch=='3')
        return 3;
    if(ch=='4')
        return 4;
    if(ch=='5')
        return 5;
    if(ch=='6')
        return 6;
    if(ch=='7')
        return 7;
    if(ch=='8')
        return 8;
    if(ch=='9')
        return 9;
    if(ch=='T')
        return 10;
    if(ch=='J')
        return 11;
    if(ch=='Q')
        return 12;
    if(ch=='K')
        return 13;
    return 14;
    //  2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < T < J < Q < K < A
}

void print(point p[])
{
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    for(int i=0; i<13; i++)
        cout << "|" << p[i].ace << " " << p[i].ace;
    cout << "|" << endl;

    for(int i=0; i<13; i++)
        cout << "| " << p[i].color << " ";
    cout << "|" << endl;

    for(int i=0; i<13; i++)
        cout << "|" << p[i].ace << " " << p[i].ace;
    cout << "|" << endl;

    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
}


bool cmp(point a,point b)
{
    if(a.color==b.color)
    {
        return toace(a.ace)<toace(b.ace);
    }
    return toco(a.color)<toco(b.color);
}

int main()
{
    while(cin >> dir)
    {
        if(dir=='#')
            break;

        int dirint=to(dir);

        point South[13],West[13],North[13],East[13];
        int cnts,cntw,cntn,cnte;
        cnts=cntw=cntn=cnte=0;

        for(int i=1; i<=52; i++)
        {
            dirint=(4+dirint+1)%4;
            switch(dirint)
            {
            case 0:
                cin >> North[cntn].color >> North[cntn].ace;
                cntn++;
                break;

            case 1:
                cin >> East[cnte].color >> East[cnte].ace;
                cnte++;
                break;

            case 2:
                cin >> South[cnts].color >> South[cnts].ace;
                cnts++;
                break;

            case 3:
                cin >> West[cntw].color >> West[cntw].ace;
                cntw++;
                break;
            }
        }
        sort(South,South+13,cmp);
        sort(West,West+13,cmp);
        sort(North,North+13,cmp);
        sort(East,East+13,cmp);

        cout << "South player:" << endl;
        print(South);
        cout << "West player:" << endl;
        print(West);
        cout << "North player:" << endl;
        print(North);
        cout << "East player:" << endl;
        print(East);
        cout << endl;
    }
    return 0;
}
