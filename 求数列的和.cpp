#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i;
    double sum;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        double a[m];
        a[0]=m;
        sum=a[0];
        for (i=1;i<n;i++)
            {
                a[i]=sqrt(a[i-1]);
                sum+=a[i];
            }
            printf("%.2f\n",sum);
    }
        return 0;
}
