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

ll gcd(ll m, ll n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll a, b;
    while(cin >> a >> b)
    {
        if(a == b)
            cout << a << endl;
        else
        {
            ll temp1 = max(a, b);
            ll temp2 = min(a, b);
            if(temp1 % temp2 == 0)
                cout << temp2 << endl;
            else
                cout << gcd(temp1, temp2) << endl;
        }
    }
    return 0;
}

