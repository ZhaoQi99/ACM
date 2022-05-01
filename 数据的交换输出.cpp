#include <stdio.h>
int main()
{
    int t,i,little,temp;
    while(scanf("%d",&t))
    {
        if(t==0)break;
        int a[t];
        for(i=0;i<t;i++)
            scanf("%d",&a[i]);
        little=a[0];
        temp=0;
        for(i=1;i<t;i++)
        {
            if(a[i]<little)
            {
                little=a[i];
                temp=i;
            }
            else;
        }
        a[temp]=a[0];
        a[0]=little;
        for(i=0;i<t-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    return 0 ;
}
