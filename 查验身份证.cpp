#include<stdio.h>
#include<stdlib.h>
int fun(char n[20])
{
    int z,i,m;
    z=0;
    for(i=0;i<17;i++)
    {
        if(n[i]=='x') return -1;
        m=n[i]-48;
        switch(i)
        {
            case 0: z=z+m*7; break;
            case 1: z=z+m*9; break;
            case 2: z=z+m*10; break;
            case 3: z=z+m*5; break;
            case 4: z=z+m*8; break;
            case 5: z=z+m*4; break;
            case 6: z=z+m*2; break;
            case 7: z=z+m*1; break;
            case 8: z=z+m*6; break;
            case 9: z=z+m*3; break;
            case 10: z=z+m*7; break;
            case 11: z=z+m*9; break;
            case 12: z=z+m*10; break;
            case 13: z=z+m*5; break;
            case 14: z=z+m*8; break;
            case 15: z=z+m*4; break;
            case 16: z=z+m*2; break;
        }
    }
    z=z%11;
    return z;
}
char M[11]={'1','0','x','9','8','7','6','5','4','3','2'};
int main()
{
    char number[20];
    int t,z,n=0,temp;
    char m;
    scanf("%d",&t);
    temp=t;
    while(t--)
    {
        scanf("%s",&number);
        z=fun(number);
        m=number[17];
        if(m==M[z]&&z!=-1)n++;
        else printf("%s\n",number);
    }
    if(n==temp)printf("All passed");
    return 0;
}
