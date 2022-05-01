#include<stdio.h>
int main()
{
    int t;
    int i,sum;
    int a[1000];
    while(scanf("%d",&t)!=EOF)
    {
        sum=1;
        for (i=0;i<t;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==1)
                sum*=a[i];
            else;
        }
    printf("%d\n",sum);
    }
    return 0;
}
