#include <stdio.h>
#include <string.h>
#define N 60
int main()
{
    int n;
    int a, b;
    double str[N][N];
    int i, j, k, l;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (j > i && j <= i + 2 && j != N - 1)
                str[i][j] = 1;
            else
                str[i][j] = 0;
        }
    for (i = N - 2; i >= 2; i--)
        for (j = i - 1; j >= 1; j--)
            for (k = j + 1; k <= j + 2; k++)
            {
                str[j][i] += str[k][i];
            }

    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            scanf("%d%d", &a, &b);
            printf("%.0lf/n", str[a][b]);
        }
    }
    return 0;
}
