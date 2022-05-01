/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

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
const double eps = 1e-6;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b, c, d, v, t;
        cin >> a >> b >> c >> d >> v >> t;
        ll ans = 0;
        bool flag = false;
        double timer = 0;
        for(double time = 0; abs(time - t) > eps; time += 0.5)
        {
            ll temp = static_cast<ll>(time + eps);
            double tt = (double)temp + 0.5;
            if(flag == true)
            {
                timer -= 0.5;
            }
            if(abs(timer - 0) < eps)
            {
                flag = false;
            }
            if(abs(tt - time) < eps)
            {
                continue;
            }
            if(temp % a == 0)
            {
                if(flag == true)
                {
                    ans += b;
                }
                else
                {
                    flag = true;
                    ans += b - 1;
                }
                timer = (double)v + 0.5;
            }
            if(temp % c == 0)
            {
                if(flag == true)
                {
                    ans += d;
                }
                else
                {
                    flag = true;
                    ans += d - 1;
                }
                timer = (double)v + 0.5;
            }
        }
        if(abs(timer - 0) < eps)
        {
            flag = false;
        }
        if(t % a == 0)
        {
            if(flag == true)
            {
                ans += b;
            }
            else
            {
                flag = true;
                ans += b - 1;
            }
        }
        if(t % c == 0)
        {
            if(flag == true)
            {
                ans += d;
            }
            else
            {
                flag = true;
                ans += d - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

