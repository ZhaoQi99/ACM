#include<stdio.h>
#include<math.h>
int fun(int n)
{
    long  long sum,i;
    if(n==1)
        sum=1;
    else
        sum=2;
    for(i=2;i<sqrt(n);i++)
    {
      if(n%i==0)
        sum+=2;
      if(sqrt(n)-(int)(sqrt(n))<0.000001)
        sum++;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long  n,p;
        scanf("%d %d",&n,&p);
        if(fun(n)==p)
             printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
