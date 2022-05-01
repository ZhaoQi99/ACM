/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll fun(ll n)
{
    if(n==1)
        return 1;
    ll ans=0;
    for(ll i=n/2;i>0;i--)
        ans+=fun(i);
    return ans+1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    ll ans=fun(n);
    cout<<ans<<endl;
    return 0;
}

