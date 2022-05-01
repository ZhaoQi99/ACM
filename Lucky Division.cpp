#include<stdio.h>
int main()
{
    int n,i,flag;
    scanf("%d",&n);
    int lucky[14]={4,7,44,47,74,77,444,447,474,477,744,747,474,777};
    flag=0;
    for (i=0;i<14;i++)
    {
        if ((lucky[i]<n)||(lucky[i]==n))
        {
            if ((n==lucky[i])||(n%lucky[i]==0))
            {
                flag=1;break;
            }
            else flag=0;
        }
        else {flag=0;break;}
    }
    if(flag==1)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
