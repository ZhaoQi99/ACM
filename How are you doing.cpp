#include <stdio.h>
int main()
{
    char a [5][6]={{"how"},{"are"},{"you"},{"doing"},{"?"}};
    char b[30];
    int i,j;
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=5;j++)
        printf ("%c",a[i][j]);
        printf ("\n");
    }
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=5;j++)
            {
                b[j+4*i]=a[i][j];
                printf ("%c",b[j+4*i]);
            }
    }
    return 0;
}
