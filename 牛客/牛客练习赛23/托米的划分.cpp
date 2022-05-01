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

ll fun(ll x)
{
    ll ans = 0;
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;
    if(x % 2 == 0)
    {
        ans += x * x / 4 + fun(x / 2) * 2;
    }
    else
    {
        ll temp1 = (x / 2) * (x - x / 2) + fun(x / 2) + fun(x - x / 2);
        //ll temp2 = (x / 2 + 1) * (x - x / 2 - 1) + fun(x / 2 + 1) + fun(x - x / 2 - 1);
        //ans += max(temp1, temp2);
        ans+=temp1;
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        ll x;
        cin >> x;
        //ll ans = fun(x);
        x--;
        ll ans=x*(x+1)/2;
        cout << ans<<endl ;
        /*
        if(i!=t)
            cout<<" ";
        else
            cout<<endl;
        */
    }
    return 0;
}

