/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    forn(i,n)
    {
        cin>>a[i];
    }
    ll flag=0;
    forn(i,n)
    {
        flag+=a[i];
        cout<<flag/m<<" ";
        flag%=m;
    }
    return 0;
}

