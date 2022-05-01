#include<iostream>
using namespace std;
int isPrime( int n )
{
    if(n<= 1)
        return 0;
    for(int i=2; i*i<=n;++i)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long t,temp=0;
    cin>>t;
    long long a[10000];
    for(int i=1;i<t+10;i++)
    {
        if(isPrime(i)==1)
            a[temp++]=i;
    }
    long long temp2=t;
    int b[10000];
    for(int i=0;i<1000;i++)
        b[i]=0;
    for(int i=2;i<=t;i++)
    {
        temp2=i;
        for(int j=0;i>=a[j];j++)
        {
            if(temp2%a[j]==0)
            {
                b[j]++;
                temp2=temp2/a[j];
                j--;
            }
            else temp2=i;
        }
    }
    for(int i=0;a[i]<=t;i++)
        cout<<a[i]<<" "<<b[i]<<endl;
    return 0;
}
