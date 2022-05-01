#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int i,sum;
    for(i=0;i<=n;i++)
    {
        sum+=5*i;
        if (sum>240) break;
        else;
    }
   printf("%d",i-1);
   return 0;
}
