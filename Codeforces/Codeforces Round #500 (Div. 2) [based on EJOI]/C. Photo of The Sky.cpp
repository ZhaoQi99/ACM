/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[2*n+1];
    for(ll i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1,a+2*n+1);
    ll ans1=(a[2*n]-a[n+1])*(a[n]-a[1]);
    for(ll i=1;i<=n-1;i++)
    {
        ll t1=a[2*n]-a[1];
        ll t2=a[i+n]-a[i+1];
        ans1=min(ans1,t1*t2);
    }
    cout<<ans1<<endl;
    return 0;
}

