///WA
/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef unsigned long long ll;
int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
ll mod=1e9+7;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    n--;
    ll l=0;
    for(ll i=0;i<n;i++)
    {
        ll x,y,aa;
        cin>>x>>y>>aa;
        l=(l+aa)%mod;
    }
    ll ans=1;
    for(ll i=n;i>=1;i--)
    {
        ans=(ans*i)%mod;
    }
    ans=(ans*n)%mod;
    ans=(ans*2)%mod;
    ans=(ans*l)%mod;
    cout<<ans<<endl;
    return 0;
}

