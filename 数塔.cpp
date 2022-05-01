#include<stdio.h>
int dp[1005][1005];
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int c;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            scanf("%d", &dp[i][j]);
    }
    int i, j;
    for(i = n - 1; i > 0; i--)
    {
        for(j = n - 1; j > 0; j--)
        {
            dp[i - 1][j - 1] += max(dp[i][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[0][0]);
    return 0 ;
}
