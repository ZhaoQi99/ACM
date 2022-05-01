#include <stdio.h>
int main()
{
    int t,n,i;
    double sum,a;
    sum=1;
    scanf("%d",&t);
    while (t--)
    {
       sum=1;
       scanf("%d",&n);
       for(i=2;i<n+1;i++)
       {
           a=i;
           a=(1/a);
           if(i%2==0)sum-=a;
           else sum+=a;
       }
       printf("%.2f\n",sum);
    }
    return 0;
}
