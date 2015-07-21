#include <iostream>
#include <cstring>
#define INF 99999999
using namespace std;

char str[30];
int p[30];
int len;

int dfs(int i,int len,int num)
{
    if(i == len)
        return p[len-1]?INF:num;
    if(p[i-1])
        !p[i-1],p[i]=!p[i],p[i+1]=!p[i+1],++num;
    return dfs(i+1,len,num);
}

int main()
{
    while(cin >> str)
    {
        int sum=INF;
        len=strlen(str);
        for(int i=0; i<len; i++)
            p[i]=str[i]-'0';
        p[0]=!p[0],p[1]=!p[1];
        sum=min(sum,dfs(1,len,1));
        for(int i=0; i<len; ++i)
            p[i]=str[i]-'0';
        sum=min(sum,dfs(1,len,0));
        if(sum == INF)
            cout<<"NO"<<endl;
        else
            cout<<sum<<endl;

    }
    return 0;
}
