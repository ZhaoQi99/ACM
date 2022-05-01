/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fun(ll x)
{
    if(x<=100)
        return fun(fun(x+11));
    else
        return x-10;
}

ll fun2(ll x)
{
    if(x<=100)
        return 91;
    else
        return x-10;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    ll n;
    scanf("%lld",&n);
    while(n--)
    {
        ll x;
        scanf("%lld",&x);
        ll ans=fun2(x);
//        x=i++;
//        ll ans=fun(x);
        printf("%lld\n",ans);
    }
    return 0;
}

