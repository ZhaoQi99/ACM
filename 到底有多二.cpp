#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
    char a[60];
    int fu(0);
    float temp(0);
    long long b;
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='2') temp++;
    }
    if(a[0]=='-')
    {
        fu=1;
        for(int i=0;i<strlen(a);i++)
            a[i]=a[i+1];
    }
    temp/=strlen(a);
    b=atoi(a);
    if(fu==1)temp*=1.5;
    if(b%2==0) temp*=2;
    temp=temp*100;
    printf("%.2f%%",temp);
    return 0;
}
