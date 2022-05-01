#include<stdio.h>
int main()
{
    int n, m, a = 0, i, x = 0, y = 0;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d", &m);
        if(n >= m)
        {
            for(i = 0; i < (n - m + 1); i++)
            {
                a = m + i;
                if(a % 2 == 1)
                {
                    x = x + a * a * a;
                    y = y;
                }
                if(a % 2 == 0)
                {
                    x = x;
                    y = y + a * a;
                }
            }
        }
        if(m > n)
        {
            for(i = 0; i < (m - n + 1); i++)
            {
                a = n + i;
                if(a % 2 == 1)
                {
                    x = x + a * a * a;
                    y = y;
                }
                if(a % 2 == 0)
                {
                    x = x;
                    y = y + a * a;
                }
            }
        }
        printf("%d %d\n", y, x);
        x = 0;
        y = 0;
    }
    return 0;
}

