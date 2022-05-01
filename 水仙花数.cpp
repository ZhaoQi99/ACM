#include<stdio.h>
int main()
{
 int a,b,i,j,k,f1,f2,f3;
 while((scanf("%d %d",&a,&b))!=EOF)
 {
    j=b-a+1;
    k=0;
    for(i=a;i<=b;i++)
    {
     f1=i/100;
     f2=(i-f1*100)/10;
     f3=i%10;
        if(i==f1*f1*f1+f2*f2*f2+f3*f3*f3)
        {
            if(k==0)
            printf("%d",i);
            if(k==1)
            printf(" %d",i);
            k=1;
        }
        else
        j--;
   }
    if(j==0)
    printf("no\n");
    else
    printf("\n");
 }
}
