#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

char tostr[1000010];
int len;
map<string, int>vis;


int bfs()
{
    queue <string> q;
    q.push("MI");

    string temp;

    while(!q.empty())
    {
        temp=q.front();

        if(vis[temp]==2)
            return 1;

        if(vis[temp]==0)
        {
            vis[temp]=1;
            for(int i=0; i<len; i++)
            {
                temp=q.front();
                if(temp[i]=='I'&&temp[i+1]=='I'&&temp[i+2]=='I')
                {
                    int j;
                    for(j=i; j<len-2; j++)
                        temp[j]=temp[j+3];
                    temp[j]=0;
                    q.push(temp);
                }



                temp=q.front();
                if(temp[i]=='U'&&temp[i+1]=='U')
                {
                    int j;
                    for(j=i; j<len-2; j++)
                        temp[j]=temp[j+2];
                    temp[j]=0;
                    q.push(temp);
                }


                temp=q.front();
                if(temp[i]=='M')
                {
                    int j,k;
                    string linshi;
                    for(j=i+1,k=0; j<len-1; k++,j++)
                        {
                            linshi[k]=temp[j];
                            //cout << linshi[k] << endl << temp[j] << endl;
                        }
                    linshi[j]='\0';
                    cout << linshi << endl;
                    temp[i+1]='\0';
                    cout << temp << endl << linshi << endl;
                    temp=temp+linshi;
                    //cout << temp << endl;
                    q.push(temp);
                }

            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    string a="breb";
    a[0]='d';
    a[1]='d';
    a[2]=0;
    cout << a;

    int T;
    cin >> T;
    while(T--)
    {
        vis.clear();
        cin >> tostr;

        len=strlen(tostr);

        vis[tostr]=2;

        int temp=bfs();
        cout << temp << endl;
    }
    return 0;
}
