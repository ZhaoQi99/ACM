#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long fun(long x,long y)//求最大公约数
{
    long r;
    while(y>0)
    {
      r=x%y;
      x=y;
      y=r;
    }
return x;
}
int main()
{
    long t,c,d,zheng,fenzi,fenmu,yue;
    cin>>t;
    long a[t],b[t];
    for(int i=0;i<t;i++)
    {
        scanf("%ld/%ld",&a[i],&b[i]);
        if(i==0){c=a[0];d=b[0];}
        else
        {
            c=c*b[i]+a[i]*d;//分子
            d=d*b[i];//分母
        }
    }
    zheng=c/d;
    fenzi=c-zheng*d;fenmu=d;
    yue=fun(fenzi,fenmu);
    fenzi=fenzi/yue;fenmu=fenmu/yue;
    if(zheng==0)
    {
        if(fenzi!=0)
        {
            if(fenmu<0)cout<<-fenzi<<"/"<<fabs(fenmu)<<endl;
            else cout<<fenzi<<"/"<<fenmu<<endl;
        }
        else cout<<"0"<<endl;
    }
    else
    {
        if(fenzi!=0)
        {
            if(fenmu<0)cout<<zheng<<" "<<-fenzi<<"/"<<fabs(fenmu)<<endl;//注意负号放在分子前面
            else cout<<zheng<<" "<<fenzi<<"/"<<fenmu<<endl;
        }
        else cout<<zheng<<endl;
    }
    return 0;
}
