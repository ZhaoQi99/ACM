/*
Problem:
Author:QiZhao
Data:2017-09-24
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct m
{
    ll l;
    ll r;
    ll seat;
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    while(cin >> n)
    {
        if(n == 0)
        {
            cout << "*" << endl;
            break;
        }
        m a[1003];
        for(ll i = 0; i < n; i++)
            cin >> a[i].l >> a[i].r >> a[i].seat;
        ll temp[102];
        memset(temp,0,sizeof(temp));
        for(ll i=0;i<n;i++)
        {
            for(ll j=a[i].l;j<a[i].r;j++)
                temp[j]+=a[i].seat;
        }
        sort(temp,temp+102,greater<ll>());
        cout<<temp[0]<<endl;
    }
    return 0;
}

