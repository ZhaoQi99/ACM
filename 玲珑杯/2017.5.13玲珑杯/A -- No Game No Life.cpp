/*
Problem:No Game No Life
Author:赵旗
Data:2017-05-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[1000000009];
int main( )
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll b,c,d;
    for(ll i=0;i<m;i++)
    {
        if(scanf("%lld%lld",&b,&c)==2)
        {
            cout<<a[c]<<endl;
        }
        else
        {

        }
    }
    return 0;
}
