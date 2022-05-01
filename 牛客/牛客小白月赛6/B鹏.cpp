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
ll read()
{
    ll x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    ll flag;
    cin>>flag;
    ll ans=0;
    bool start=false;
    for(ll i=0;i<n-1;i++)
    {
        ll temp;
        cin>>temp;
        if(temp>flag)
        {
            flag=temp;
            start=true;
        }
        else if(temp<flag)
        {
            if(start)
                ans++;
            flag=temp;
            start=false;
        }
    }
    cout<<ans<<endl;
    return 0;
}

