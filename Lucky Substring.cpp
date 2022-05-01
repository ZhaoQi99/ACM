#include<stdio.h>
int main()
{
    int a,b,i;
    char c[51];
    a=0;b=0;
    scanf("%s",&c);
    for (i=0;c[i]!='\0';i++)
    {
        if(c[i] == '4')
			a++;
		if(c[i] == '7')
			b++;
    }
    if(a==0&&b==0)
        printf("-1");
    else if(a>=b)
            printf("4");
        else printf("7");
}
