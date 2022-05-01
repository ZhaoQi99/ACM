#include<iostream>
using namespace std;
int f(int x)
{
    if(x<6)return 1;
    else return f(x-1)+f(x-5);
}
int main()
{
    int x;
    cin>>x;
    cout<<f(x);
    return 0;
}
