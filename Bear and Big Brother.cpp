/*
Problem:Bear and Big Brother
Author:赵旗
Data:2017-04-23
Description:简单模拟
Copyright © 2017 赵旗. All rights reserved.  
*/
#include<iostream>
#include<algorithm>

typedef long long ll;

using namespace std;
int main( )
{
    ll a,b,temp=0;
    cin>>a>>b;
    while(a<=b)
    {
        a*=3;
        b*=2;
        temp++;
    }
    cout<<temp<<endl;
    return 0;
}
