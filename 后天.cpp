#include <iostream>
using namespace std;
int main()
{
    int d,n,a;
    cin>>d;
    n=d+2;
    if(n>7)
    {
        a=n/7;
        n=n-a*7;
    }
    cout<<n;
    return 0;
}
