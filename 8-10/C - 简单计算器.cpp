#include<stdio.h>
int main()
{
    while(1)
    {
        double num[205];
        char ch[450];
        int i,j;
        int top;

        scanf("%lf",&num[0]);
        for(top=0;;)
        {

            scanf("%c",&ch[top]);
            if(ch[top]=='\n')
                break;
            scanf("%c",&ch[top++]);
            getchar();
            scanf("%lf",&num[top]);
            if(ch[top-1]=='*')
            {
                num[top-1]=num[top-1]*num[top];
                top--;
            }
            if(ch[top-1]=='/')
            {
                num[top-1]=num[top-1]*1.0/num[top];
                top--;
            }
        }
        if(num[0]==0&&ch[0]=='\n')
            break;
        double sum=num[0];
        for(i=0; ch[i]!='\n'; i++)
        {
            if(ch[i]=='+')
                sum=sum+num[i+1];
            if(ch[i]=='-')
                sum=sum-num[i+1];
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
