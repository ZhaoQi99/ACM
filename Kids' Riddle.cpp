/*
Problem:Kids' Riddle
Author:赵旗
Data:2017-04-27
Description:思维
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll n,ans=0;
    cin>>n;
    ll a[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
    if(n==0)
        ans=1;
    while(n)
    {
        ans+=a[n%16];
        n/=16;
    }
    cout<<ans<<endl;
    return 0;
}
