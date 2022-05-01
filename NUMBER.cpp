#include <stdio.h>
int f(int A,int B,long long n)
{
    if (n==1||n==2)
        return 1;
    else
        return (A*f(A,B,n-1)+B*f(A,B,n-2))%7;
}
int main()
{
  int A,B;
  long  long n;
    while (scanf("%d,%d,%d",&A,&B,&n)!=EOF)
        {
            if (A==0&&B==0&&n==0) break;
            return f(A,B,n%7);
        }
}
