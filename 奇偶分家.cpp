#include <iostream>
using namespace std;
int main()
{
    int t,b(0),c(0);
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++)
    {
        cin>>a[i];
        if(a[i]%2==0) b++;
        else c++;
    }
    cout<<c<<" "<<b;
    return 0;
}
