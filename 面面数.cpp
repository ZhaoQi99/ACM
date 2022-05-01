#include<stdio.h>
int main( )
{
  int N;
  int i,k;
  long long b[10000];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&b[i]);
  long long a[100000];
    a[0]=1;a[1]=2;a[2]=4;a[3]=8;
    for (i=4;i<100000;i++)
        a[i]=a[i-1]+2*(i-1);
  for(i=0;i<N;i++)
  {
    if (b[i]==0)
        printf("1\n");
    else
        for (k=0;k<100000;k++)
        {
            if((a[k]>b[i])||(a[k]==b[i]))
                {
                   printf("%d\n",k);
                   break;
                }
        }
    }
    return 0;
}
