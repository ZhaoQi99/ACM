//注意m>n,m<n;
#include<stdio.h>
int main()
{
    long long    m,n,t;
    long long    a,b,i;
    while (scanf("%lld %lld",&m,&n)!=EOF)
    {
        if(m>n)
        {
           t=m;m=n;n=t;
        }
        a=b=0;
        for (i=m;i<n+1;i++)
        {
            if(i%2==0) a+=(i*i);
            else b+=(i*i*i);
        }
        printf("%lld %lld\n",a,b);
    }
    return 0;
}
