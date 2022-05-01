#include <stdio.h>
#include<limits.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int count=0 ;
        int min=INT_MAX,min2=INT_MAX;
        int n=0;
        scanf("%d",&count);
        for (int i=0;i<count;++i)
        {
            scanf("%d",&n);
            if (n<min)
            {
            min2=min;
            min=n;
            continue;
                }
            if (n<min2)
            {
            min2=n;
                }
        }
    printf( "%d\n", min2);
    }
}
