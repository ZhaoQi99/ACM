#include<stdio.h>
int main()
{
    long long n;
    int min1,min2,min3,max1,max2,max3;
    int a,b,c;
    scanf("%d%d%d%d%d%d%d",&n,&min1,&max1,&min2,&max2,&min3,&max3);
    a=n-min2-min3;
    if (a>=max1)
        a=max1;
    n=n-a;
    b=n-min3;
    if(b>=max2)
        b=max2;
    c=n-b;
    printf("%d %d %d",a,b,c);
    return 0;
}
