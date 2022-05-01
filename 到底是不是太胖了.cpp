#include<iostream>
#include<cmath>
using namespace std;
float fun(float h)
{
    float b;
    b=(h-100)*0.9*2.0;
    return b;
}
int main()
{
    int t;
    cin>>t;
    float h,w;
    while(t--)
    {
        cin>>h>>w;
        h=fun(h);
        if(fabs(h-w)+0.0000001<0.1*h)
            cout<<"You are wan mei!"<<endl;
        else if(h+0.000001<w)
            cout<<"You are tai pang le!"<<endl;
            else cout<<"You are tai shou le!"<<endl;
    }
    return 0;
}
