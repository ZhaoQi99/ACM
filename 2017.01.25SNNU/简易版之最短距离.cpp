#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
 int m,i,j,n,k,line;
 int a[510],b[510];
 scanf("%d",&m);
 for (i=0;i<m;i++)
 {
     scanf("%d",&n);
     for(j=0;j<n;j++)
     {
         scanf("%d",&a[j]);
     }
     for (k=0;k<n;k++)
    {
        b[k]=0;
        for (j=0;j<n;j++)
        {
            b[k]=b[k]+abs(a[j]-a[k]);
        }
    }
    line=b[0];
    for (k=0;k<n;k++)
    {
        if(b[k]<line) line=b[k];
        else;
    }
     printf("%d\n",line);
 }
 return 0;
}
