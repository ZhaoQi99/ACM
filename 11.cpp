#include  <stdio.h>
#include  <string.h>
char str[250];
int main ()
{
    int M1, M2, M3;
    int R1, R2, R3;
    int i, l;
    while (scanf("%d%d", &M1, &M2) != EOF)
    {
        R1 = R2 = R3 = 0;
        scanf("%s", &str);
        getchar();
        l = strlen(str);
        for (i = 0; i < l; i++)
        {
            if(str[i] == 'A')
                R1 = M1;
            else if(str[i] == 'B')
                R2 = M2;
            else if(str[i] == 'C')
                M1 = R3;
            else if(str[i] == 'D')
                M2 = R3;
            else if(str[i] == 'E')
                R3 = R1 + R2;
            else if(str[i] == 'F')
                R3 = R1 - R2;
        }
        printf("%d,%d\n", M1, M2);
    }
    return 0;
}
