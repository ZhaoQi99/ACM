/*
Problem:最大公约数GCD(51 nod 1011)
Author:赵旗
Data:2017-05-07
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll fun(ll &x, ll &y)
{
    ll z = y;
    while(x%y!=0)
    {
        z = x%y;
        x = y;
        y = z;
    }
    return z;
}
int main( )
{
    ll a,b;
    cin>>a>>b;
    cout<<fun(a,b)<<endl;
    return 0;
}
