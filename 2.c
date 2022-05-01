#include <stdio.h>
int main()
{
    long long n;
    long long sum;
    while(scanf("%I64d",&n)!=EOF)
    {
        sum=n*(n+1)/2;
        printf("%I64d\n\n",sum);
    }
    return 0;
}
