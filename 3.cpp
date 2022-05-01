#include <math.h>
#include <stdio.h>
int main()
{
    double r;
    while (scanf("%lf", &r) != EOF)
    {
         r=fabs(r);
        printf("%.2lf\n",r);
    }
    return 0;
}
