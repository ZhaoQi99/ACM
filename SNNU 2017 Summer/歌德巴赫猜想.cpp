/*
Problem:歌德巴赫猜想
Author:赵旗
Data:2017-07-11
Description:判断素数，枚举
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool is(ll x)
{
    for(ll i=2;i*i<x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int main( )
{
    cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i=2;i<n;i++)
    {
        if(is(i)&&is(n-i))
        {
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
    return 0;
}
