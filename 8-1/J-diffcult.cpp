#include<iostream>

using namespace std;

bool ans[301][301][301];

void slov()
{
    for(int i=0; i<=300; i++)
        for(int j=0; j<=300; j++)
            for(int k=0; k<=300; k++)
                if(!ans[i][j][k])
                {
                    for(int I=i+1; I<=300; I++)
                        ans[I][j][k]=1;

                    for(int I=j+1; I<=300; I++)
                        ans[i][I][k]=1;

                    for(int I=k+1; I<=300; I++)
                        ans[i][j][I]=1;

                    int Ix,Iy,Iz;
                    for(Ix=i+1,Iy=j+1; Ix<=300&&Iy<=300; Ix++,Iy++)
                        ans[Ix][Iy][k]=1;

                    for(Iy=j+1,Iz=k+1; Iy<=300&&Iz<=300; Iy++,Iz++)
                        ans[i][Iy][Iz]=1;

                    for(Ix=i+1,Iz=k+1; Ix<=300&&Iz<=300; Ix++,Iz++)
                        ans[Ix][j][Iz]=1;
                }
}

int main()
{
    slov();
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        cout << ans[a][b][c] << endl;
    }
    return 0;
}
