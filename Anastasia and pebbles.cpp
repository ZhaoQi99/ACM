/*
Problem:Anastasia and pebbles
Author:赵旗
Data:2017-04-26
Description:模拟
Copyright © 2017 赵旗. All rights reserved.  
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll fun(ll x,ll k);
int main( )
{
    ll n,k,sum=0;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        sum+=fun(x,k);
    }
    if(sum%2==0)
        cout<<sum/2<<endl;
    else
        cout<<sum/2+1<<endl;
    return 0;
}
ll fun(ll x,ll k)
{
    ll temp;
    if(x%k)
        temp=x/k+1;
    else
        temp=x/k;
    return temp;
}
