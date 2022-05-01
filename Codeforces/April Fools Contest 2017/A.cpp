#include<iostream>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    unsigned  a[t+10],b[t+10];
    for(long long  i=0;i<t;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]&&i>0)
        {
            long long t;
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
    }
    for(long long  i=0;i<t;i++)
    {
        cin>>b[i];
        if(a[i]<a[i-1]&&i>0)
        {
            long long t;
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
    }
    long long  sum=0;
    for(long long  i=0;i<t;i++)
        sum+=a[i]*b[i];
    cout<<sum<<endl;
    return 0;
}
