#include<stdio.h>
#include<string.h>
 int main()
 {
     int v,n,a[100],b[100];
     while(scanf("%d %d",&v,&n),v)
     {
         int money=0;
         memset(a,0,sizeof(a));
         memset(b,0,sizeof(b));
         for(int i=0;i<n+1;i++)
             {
                 if(i!=n)
                 scanf("%d%d",&a[i],&b[i]);
                 else scanf("%d",&a[i],&b[i]);
             }
         for(int i=0;i<n;i++)
             for(int j=0;j<n-i-1;j++)
             {
                 if(a[j]<a[j+1])
                 {
                     int t;t=a[j];a[j]=a[j+1];a[j+1]=t;
                     int k=b[j];b[j]=b[j+1];b[j+1]=k;
                 }
             }
         for(int i=0;i<n;i++)
         {
            if(b[i]<v)
            {
                money+=a[i]*b[i];
                v=v-b[i];
            }
            else
            {
                money+=v*a[i];
                break;
            }
         }
        printf("%d\n",money);
     }
    return 0;
 }
