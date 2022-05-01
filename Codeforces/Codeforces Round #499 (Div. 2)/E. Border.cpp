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

ll gcd(ll a, ll b)
{
    if(a<b)
        swap(a,b);
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll g=0;
    for(int i = 0; i < n; i++)
    {
        ll t;
        cin>>t;
        g=gcd(t,g);
    }
    set<ll> ans;
    for(ll i=1;i<=k;i++)
    {
        ans.insert(i*g%k);
    }
    cout<<ans.size()<<endl;
    set<ll>::iterator t=ans.begin();
    for(;t!=ans.end();)
    {
        cout<<*t;
        if(++t!=ans.end())
            cout<<" ";
    }
    cout<<endl;
    return 0;
}

