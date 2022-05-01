#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float a,b;
    cin>>a;
    b=(a-100)*0.9*2;
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<b;
    return 0;
}
