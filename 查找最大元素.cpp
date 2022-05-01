#include <stdio.h>
#include<string.h>
char output(char a[],char MAX,int b)
{
    int i;
    for (i=0;i<b;i++)
    {
        if(a[i]!=MAX) printf("%c",a[i]);
        else printf("%c(max)",a[i]);
    }
    printf("\n");
    return 0;
}
int main()
{
    char a[105];
    int b,i;
    char MAX;
    while(gets(a))
    {
        b=strlen(a);
        MAX=a[0];
        for(i=1;i<b+1;i++)
        {
            if(a[i]>MAX) MAX=a[i];
            else;
        }
        output(a,MAX,b);
        memset(a,0,b);
    }
    return 0;
}
