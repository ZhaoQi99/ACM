#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    int t, r,i;
    scanf("%d",&t);
    getchar();
    while (t--)
        {
            r=0;
            gets(s);
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                    r++;
                if (s[i]=='\0')
                    break;
            }
        printf("%d\n", r);
        }
    return 0;
}
