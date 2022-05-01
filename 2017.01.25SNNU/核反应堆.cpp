#include<stdio.h>
int main()
{
 long long gao[40],di[40];
 int i,n;
 gao[0]=1;
 di[0]=0;
 for(i=1;i<35;i++)
 {
     gao[i]=gao[i-1]*3+di[i-1]*2;
     di[i]=gao[i-1]+di[i-1];
 }
 while (~scanf("%d",&n)&&n!=-1)
 {
        printf("%I64d, %I64d\n",gao[n],di[n]);
 }
 return 0;
}
