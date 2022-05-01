//未知错误
#include <stdio.h>
int output(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}
int main()
{
    int m,n,i,j;
    while(scanf("%d%d",&n,&m))
    {
        if(m==0&&n==0) break;
        else;
        int a[n+1];
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n==0) printf("%d",m);
        else
        {
        for(i=0;i<n;i++)
        {
            if (a[i]>m)
            {
                for(j=n;j>i;j--)
                {
                    a[j]=a[j-1];
                }
                a[i]=m;
            }
            else;
        }
        output(a,n);
        }
    }
    return 0;
}
