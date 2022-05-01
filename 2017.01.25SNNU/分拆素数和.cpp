#include<stdio.h>
int fun(int n)
{
    int flag,k,s;
    flag=1;
    for (k=2;k*k<=n;k++)
    {
        if(n%k==0)
        {
            flag=0;
            break;
        }
    }
    if(n==1) flag=0;
    if(n==2) flag=1;
    return flag;
}
int main()
{
    int sum,i,n;
    scanf("%d",&n);
    while (n!=0)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
           if(fun(i)==1)
            if(fun(n-i)==1)
                {sum++;}
        }
        printf("%d\n",sum/2);
        scanf("%d",&n);
    }
    return 0;
}
