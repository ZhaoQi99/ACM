#include<stdio.h>
#include<string.h>
int main()
{
    char a[10000];
    int i,j,k;
    gets(a);
    char b[300];
    gets(b);
    for(i=0;i<strlen(a);i++)
    {
        for(j=0;j<strlen(b);j++)
        {
            if(b[j]==a[i])
            {
                for(k=i;k<strlen(a);k++)
                    a[k]=a[k+1];
            break;
            }
        }
    }
    for(i=0;i<strlen(a);i++)
        printf("%c",a[i]);
    return 0;
}
