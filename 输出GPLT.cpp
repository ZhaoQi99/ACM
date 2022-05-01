#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int fun(int a,int b,int c,int d)
{
    int big;
    big=a;
    if (b>big) big=b;
    if (c>big) big=c;
    if (d>big) big=d;
    return big;
}
int main()
{
    char name[10000];
    gets(name);
    int a(0),b(0),c(0),d(0),temp;
    for(int i=0;i<strlen(name);i++)
    {
        switch(name[i])
        {
            case 'g':;
            case 'G': a++;break;
            case 'p':;
            case 'P': b++;break;
            case 'l':;
            case 'L': c++;break;
            case 't':;
            case 'T': d++;break;
            default :break;
        }
    }
    temp=fun(a,b,c,d);
    for(int i=0;i<temp;i++)
    {
        if(a!=0) {cout<<'G';a--;}
        if(b!=0) {cout<<'P';b--;}
        if(c!=0) {cout<<'L';c--;}
        if(d!=0) {cout<<'T';d--;}
    }
    return 0;
}
