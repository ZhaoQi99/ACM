#include "stdio.h"
int main()
{
    double m;
    int n, fu, zero, zheng;
    while(scanf("%d", &n) != EOF)
    {
        fu = 0;
        zero = 0;
        zheng = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &m);
            if(m < 0)
                fu++;
            else if(m == 0)
                zero++;
            else
                zheng++;
        }
        printf("%d %d %d\n", fu, zero, zheng);
    }
    return 0;
}
