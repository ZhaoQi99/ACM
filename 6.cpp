#include<stdio.h>
int main()
{
    int n,i,s=1,a;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            if(a%2==1)
                s=s*a;
            else s=s;
        }
        printf("%d\n",s);
        s=1;
        i=0;
    }
    return 0;
}
