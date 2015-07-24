#include <iostream>
#include <cstring>
using namespace std;

int w;
char num[15];
int len;

char ch[][15]
{
    {
        ' ','-',' ',
        '|',' ','|',
        ' ',' ',' ',
        '|',' ','|',
        ' ','-',' ',
    },
    {
        ' ',' ',' ',
        ' ',' ','|',
        ' ',' ',' ',
        ' ',' ','|',
        ' ',' ',' ',
    },
    {
        ' ','-',' ',
        ' ',' ','|',
        ' ','-',' ',
        '|',' ',' ',
        ' ','-',' ',
    },
    {
        ' ','-',' ',
        ' ',' ','|',
        ' ','-',' ',
        ' ',' ','|',
        ' ','-',' ',
    },
    {
        ' ',' ',' ',
        '|',' ','|',
        ' ','-',' ',
        ' ',' ','|',
        ' ',' ',' ',
    },
    {
        ' ','-',' ',
        '|',' ',' ',
        ' ','-',' ',
        ' ',' ','|',
        ' ','-',' ',
    },
    {
        ' ','-',' ',
        '|',' ',' ',
        ' ','-',' ',
        '|',' ','|',
        ' ','-',' ',
    },
    {
        ' ','-',' ',
        ' ',' ','|',
        ' ',' ',' ',
        ' ',' ','|',
        ' ',' ',' ',
    },
    {
        ' ','-',' ',
        '|',' ','|',
        ' ','-',' ',
        '|',' ','|',
        ' ','-',' ',
    },
    {
        ' ','-',' ',
        '|',' ','|',
        ' ','-',' ',
        ' ',' ','|',
        ' ','-',' ',
    }
};

int main()
{
    /*for(int k=0; k<=9; k++)
    {
        for(int i=0; i<15; i++)
        {
            cout << ch[k][i];
            if(i%3==2)
                cout << endl;
        }
        cout << endl;
    }*/


    while(cin >> w >> num)
    {
        if(w==0&&num[0]=='0')
            break;
        len=strlen(num);

        for(int i=0; i<len; i++)
        {
            cout << ch[num[i]-'0'][0];
            for(int k=0; k<w; k++)
                cout << ch[num[i]-'0'][1];
            cout << ch[num[i]-'0'][2];
            if(i!=len-1)
                cout << " ";
        }
        cout << endl;

        for(int l=0; l<w; l++)
        {
            for(int i=0; i<len; i++)
            {
                cout << ch[num[i]-'0'][3];
                for(int k=0; k<w; k++)
                    cout << ch[num[i]-'0'][4];
                cout << ch[num[i]-'0'][5];
                 if(i!=len-1)
                    cout << " ";
            }
            cout << endl;
        }

        for(int i=0; i<len; i++)
        {
            cout << ch[num[i]-'0'][6];
            for(int k=0; k<w; k++)
                cout << ch[num[i]-'0'][7];
            cout << ch[num[i]-'0'][8];
             if(i!=len-1)
                cout << " ";
        }
        cout << endl;


        for(int l=0; l<w; l++)
        {
            for(int i=0; i<len; i++)
            {
                cout << ch[num[i]-'0'][9];
                for(int k=0; k<w; k++)
                    cout << ch[num[i]-'0'][10];
                cout << ch[num[i]-'0'][11];
                 if(i!=len-1)
                    cout << " ";
            }
            cout << endl;
        }

        for(int i=0; i<len; i++)
        {
            cout << ch[num[i]-'0'][12];
            for(int k=0; k<w; k++)
                cout << ch[num[i]-'0'][13];
            cout << ch[num[i]-'0'][14];
             if(i!=len-1)
                cout << " ";
        }
        cout << endl;

     cout << endl;
    }
}
