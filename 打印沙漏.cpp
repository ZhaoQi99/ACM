#include<stdio.h>
int output(int k,char c,int temp2,int l)
{
    int j,m;
    for(m=0;m<l;m++)
            printf(" ");
    for (j=0;j<(2*temp2+1);j++)
            putchar(c);
    return 0;
}
int main()
{
    int n,i,left,temp1,temp2,k,l;
    char c;
    scanf("%d",&n);
    getchar();
    scanf("%c",&c);
    int a[1000];
    a[0]=1;a[1]=7;a[2]=17;a[3]=31;
    for (i=4;i<100;i++)
        a[i]=a[i-1]+2*(2*i+1);
    for (i=0;i<1000;i++)
    {
        if(n>=a[i]&&n<=a[i+1])
        {
            left=n-a[i];
            n=a[i];
            temp1=temp2=i;
            break;
        }
    }
    k=i;
    l=0;
    for(i=0;i<temp1+1;i++)
    {
        output(k,c,temp2,l);
        printf("\n");
        temp2--;
        l++;
    }
    l-=2;
    temp2+=2;
    for(i=0;i<temp1;i++)
    {
        output(k,c,temp2,l);
        printf("\n");
        temp2++;
        l--;
    }
    printf("%d",left);
    return 0;
    }

