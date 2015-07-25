#include <iostream>

using namespace std;

char map[10][10];

int slov(int xx,int yy)
{
    int x,y;
    int cnt;
    int ans=0;

    x=xx,y=yy,cnt=0;

    int i,j;

    for(int i=y+1; i<8; i++)
    {
        if(map[x][i]=='L')
        {
            cnt++;
            continue;
        }

        if(map[x][i]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[x][i]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }

    x=xx,y=yy,cnt=0;
    for(int i=y-1; i>=0; i--)
    {
        if(map[x][i]=='L')
        {
            cnt++;
            continue;
        }

        if(map[x][i]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[x][i]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }

    x=xx,y=yy,cnt=0;
    for(int i=x+1; i<8; i++)
    {
        if(map[i][y]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][y]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][y]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }


    x=xx,y=yy,cnt=0;
    for(int i=x-1; i>=0; i--)
    {
        if(map[i][y]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][y]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][y]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }


    x=xx,y=yy,cnt=0;
    for(i=x+1,j=y+1; i<8&&j<8; i++,j++)
    {
        if(map[i][j]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][j]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][j]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }

    x=xx,y=yy,cnt=0;
    for(i=x+1,j=y-1; i<8&&j>=0; i++,j--)
    {
        if(map[i][j]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][j]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][j]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }

    x=xx,y=yy,cnt=0;
    for(i=x-1,j=y+1; i>=0&&j<8; i--,j++)
    {
        if(map[i][j]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][j]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][j]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }


    x=xx,y=yy,cnt=0;
    for(i=x-1,j=y-1; i>=0&&j>=0; i--,j--)
    {
        if(map[i][j]=='L')
        {
            cnt++;
            continue;
        }

        if(map[i][j]=='D')
        {
            ans=ans+cnt;
            break;
        }

        if(map[i][j]=='*')
        {
            //ans=ans+cnt;
            break;
        }
    }
   return ans;
}

int main()
{
    int T;
    cin >> T;
    int N=0;
    while(T--)
    {
        N++;
        int anss=0;

        for(int i=0; i<8; i++)
            cin >> map[i];

        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                if(map[i][j]=='*')
                    anss=max(anss,slov(i,j));

        cout << "Case "<< N <<": "<<anss<< endl;
    }
    return 0;
}
