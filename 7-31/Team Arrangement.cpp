#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Player
{
    int num;
    string name;
    char role;
    int year;
} play[22];

int tonum(char ch)
{
    if(ch=='G')
        return 0;
    if(ch=='D')
        return 1;
    if(ch=='M')
        return 2;
    if(ch=='S')
        return 3;
}

bool cmp1(Player a,Player b)
{
    if(a.role!=b.role)
        return tonum(a.role)<tonum(b.role);
    return a.num<b.num;
}

bool cmp2(Player a,Player b)
{
    if(a.year!=b.year)
        return a.year>b.year;
    return a.num>b.num;
}

int main()
{
    while(cin >> play[0].num && play[0].num)
    {
        for(int i=0; i<22; i++)
        {
            if(i)
                cin >> play[i].num;
            cin >> play[i].name >> play[i].role;
            int s,e;
            char ch;
            play[i].year=0;
            while(scanf("%d-%d%c",&s,&e,&ch))
            {
                play[i].year=play[i].year+e-s+1;
                if(ch=='\n')
                    break;
            }
        }
        int D,M,S;
        scanf("%d-%d-%d",&D,&M,&S);
        sort(play,play+22,cmp1);
        Player chose[11];
        int ok=1;
        int tot=0;
        if(play[0].role=='G')
            chose[tot++]=play[0];
        else
            ok=0;
        for(int i=0; i<22; i++)
        {
            if(play[i].role=='D'&&D)
            {
                chose[tot++]=play[i];
                D--;
            }
            if(play[i].role=='M'&&M)
            {
                chose[tot++]=play[i];
                M--;
            }
            if(play[i].role=='S'&&S)
            {
                chose[tot++]=play[i];
                S--;
            }
        }
        if(D||M||S)
            ok=0;
        if(ok)
        {
            sort(chose,chose+11,cmp2);
            Player temp=chose[0];
            cout << chose[0].num << " " << chose[0].name << " " << chose[0].role << endl;
            sort(chose,chose+11,cmp1);
            for(int i=0; i<11; i++)
                if(chose[i].name!=temp.name)
                    cout << chose[i].num << " " << chose[i].name << " " << chose[i].role << endl;
        }
        else
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
        cout << endl;
    }
    return 0;
}
