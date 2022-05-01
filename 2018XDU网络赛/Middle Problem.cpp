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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, m;
    while(cin >> n >> m)
    {
        ll a[100005];
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ll ans = a[n / 2 + 1];
        ll flag = a[n / 2 + 2] - a[n / 2 + 1];
        ll count = 1;
        for(ll i = n / 2 + 2; i <= n; i++)
        {
            if(m < count)
                break;
            if(m >= flag * count)
            {
                m -= count * flag;
                ans += flag;
                count++;
                flag = a[i + 1] - a[i];
            }
            else
            {
                ll temp = m / count;
                m -= temp * count;
                ans += temp;
            }
        }
        if(m >= count)
        {
            ans += m / count;
        }
        cout << ans << endl;
    }
    return 0;
}

