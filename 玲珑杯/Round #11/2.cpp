#include<stdio.h>
#include<math.h>
int f(long long i)
{
    int flag=0,loop,flag2;
    long long n,sum=0,m;
    n=i;
    while(n)
    {
        n=n/10;
        flag++;//位数
    }
    flag2=flag-1;
    for(loop=0;loop<flag;loop++)
    {
        m=i/(pow(10,flag2));
        sum=sum+m*m;
        i=i-m*pow(10,flag2);
        flag2--;
    }
    return sum;
}
int main()
{
    long long i,k;
    while(scanf("%lld",&i)!=EOF)
    {
        for(k=0;k<100000;k++)
        {
            if(i==1){printf("YES");break;}
            else     i=f(i);
        }
        if(i!=1) printf("NO");
        printf("\n");
    }
    return 0;
}
/*
DESCRIPTION
给一个数x，定义一个函数f(x)的结果是x的各位数字的平方和，若经过无数次递归操作之后若结果为1，也就是f(f(f(...f(x)...)))=1，那么这个数被认为是一个特别的数。给出一个数x请问这个数是否特别。

INPUT
包含多组测试数据(<=20)，每组数据一行一个整数x(1<=x<=1000000000)
OUTPUT
每组数据输出一行YES表示是一个特别的数，否则输出NO
SAMPLE INPUT
19
2
14
SAMPLE OUTPUT
YES
NO
NO
*/
