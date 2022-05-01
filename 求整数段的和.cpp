#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,i,n=0,sum;
    scanf("%d%d",&a,&b);
    sum=0;
    for(i=a;i<b+1;i++)
    {
        sum+=i;
        printf("%5d",i);
        n++;
        if(n%5==0) printf("\n");
    }
    if(n%5!=0) printf("\n");
    printf("Sum = %d",sum);
    return 0;
}
