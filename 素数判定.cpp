#include <stdio.h>
#include<math.h>
int fun(int n)
{
    int i;
    if(n<2)
        return 0;
    for (i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int x,y,s,i;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        if (x==0&&y==0) break;
        for (i=x;i<=y;i++)
        {
            s=i*i+i+41;
            if(fun(s)!=1)
            {
                printf ("Sorry\n");
                break;
                }
        }
        if (i==y+1)
        printf("OK\n");
    }
    return 0;
}
