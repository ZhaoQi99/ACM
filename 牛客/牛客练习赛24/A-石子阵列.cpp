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
typedef long long ll;
const ll mod=1000000007;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    ll ans=m;
    forn(i,n-1)
    {
        ans=ans*(m-1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

