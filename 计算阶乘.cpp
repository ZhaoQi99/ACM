#include<iostream>
#include<math.h>
using namespace std;
int fun (int n)
{
    int i,j=1;
    for(i=1;i<=n;i++)
    j*=i;
    return j;
}
int main()
{
    int n,s=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
    s+=fun(i);
    cout<<s;
    return 0;
}
