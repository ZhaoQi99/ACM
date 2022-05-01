#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int a,b;
    scanf("%d:%d",&a,&b);
    if(a>11)
    {
        if(a==12&&b==0)printf("Only %d:0%d.  Too early to Dang.",a,b);//注意12：00时的情况
        else if(b==0)
        {
            for (int i=0;i<a-12;i++)
            cout<<"Dang";
        }
        else
            for (int i=0;i<a-11;i++)
            cout<<"Dang";
    }
    else
    {
        if(a<10)
        {
            if(b<10) printf("Only 0%d:0%d.  Too early to Dang.",a,b);
            else  printf("Only 0%d:%d.  Too early to Dang.",a,b);
        }
        else printf("Only %d:%d.  Too early to Dang.",a,b);
    }
    return 0;
}
