#include <iostream>
#include <cstring>
using namespace std;

/*
int N;
int map[20][20];
int vis[20][20];
char ans[1000][1000];

int main()
{
    while(cin >> N && N)
    {
        memset(ans,'\0',sizeof(ans));
        for(int i=1; i<=N; i++)
            for(int j=1; j=N; j++)
                cin >> map[i][j];

        //char ans[3*N+N-1][2+3*N+N+1];

        for(int i=1; i<3*N+N-1; i=i+4)
            for(int j=1; j<3*N+N-1; j=j+2)
                j%4==1?ans[i][j]='H':ans[i][j]='O';

        for(int i=3; i<3*N+N-1; i=i+4)
            for(int j=3; j<3*N+N-1; j=j+4)
                ans[i][j]='H';


        for(int j=0; j<N; j++)
        {
            if(map[1][j]==1)
                ans[1][4*j+3-1]=ans[1][4*j+3+1]='-';

           // if(map[i][j]==0)

        }

        for(int i=1; i<N-1; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j]==-1)
                    ans[4*i+1-1][4*j+3]=ans[4*i+1+1][4*j+3]='|';
                if(map[i][j]==1)
                    ans[4*i+1][4*j+3-1]=ans[4*i+1][4*j+3+1]='-';
            }
        }

        for(int i=0; i<3*N+N-1; i++)
        {
            for(int j=0; j<3*N+N-1; j++)
                if(ans[i][j]!='\0')
                    cout << ans[i][j];
                else
                    cout << " ";

            cout << endl;
        }
    }
    return 0;
}
*/

int N;
int map[15][15];

int main()
{
    int T=0;
    while(cin >> N && N)
    {
        T++;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                cin >> map[i][j];

        cout << "Case "<< T << ":" << endl << endl;

        for(int i=0; i<4*N+3; i++)
            cout << "*";
        cout << endl;



        cout << "*";

        for(int i=1; i<=N; i++)
        {
            cout << "H";
            if(map[1][i]==1)
                cout << "-O-";
            else if(map[1][i+1]==1)
                cout << "-O ";
            else
                cout << " O-";
        }
        cout << "H*" << endl;


        for(int k=2; k<=N; k++)
        {
            cout << "*";
            for(int j=1; j<=N; j++)
            {
                cout << " ";
                if(map[k-1][j]==1)
                    cout << "   ";
                else if(map[k][j]==1)
                    cout << " | ";
                else
                    cout << " | ";
            }
            cout << " *" << endl;

            cout << "*";
            for(int j=1; j<=N; j++)
            {
                cout << " ";
                cout << " H ";
            }
            cout << " *" << endl;

            cout << "*";
            for(int j=1; j<=N; j++)
            {
                cout << " ";
                if(map[k][j]==-1)
                    cout << " | ";
                else if(map[k-1][j]==1)
                    cout << " | ";
                else if(map[k][j]==1)
                    cout << "   ";
                else
                    cout << "   ";
            }
            cout << " *" << endl;

            cout << "*";
            for(int j=1; j<=N; j++)
            {
                cout << "H";
                if(map[k][j]==1)
                    cout << "-O-";
                else if(map[k][j]==-1)
                    cout << " O ";
                else if(map[k][j+1]==1)
                    cout << "-O ";
                else if(map[k][j-1]==1)
                    cout << " O-";
                else
                    cout << " O ";
            }
            cout << "H*" << endl;
        }
    }
    return 0;
}

