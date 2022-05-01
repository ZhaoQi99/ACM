/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[25][25];
ll ans[25][25];
int main( )
{
    cin.sync_with_stdio(false);
    ll m, n;
    while(cin >> n >> m)
    {
        if(m==0&&n==0)
            return 0;
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for(ll i = 1; i <= n; i++)
        {
            for(ll k = 1; k <= m; k++)
                cin >> a[i][k];
        }
        for(ll i = 1; i <= n; i++)
        {
            for(ll k = 1; k <= m; k++)
            {
                ll temp = a[i][k];
                if(temp * a[i - 1][k] > 0)
                    ans[i][k] -= abs(a[i - 1][k]);
                else
                    ans[i][k] += abs(a[i - 1][k]);
                if(temp * a[i + 1][k] > 0)
                    ans[i][k] -= abs(a[i + 1][k]);
                else
                    ans[i][k] += abs(a[i + 1][k]);
                if(temp * a[i][k - 1] > 0)
                    ans[i][k] -= abs(a[i][k - 1]);
                else
                    ans[i][k] += abs(a[i][k - 1]);
                if(temp * a[i][k + 1] > 0)
                    ans[i][k] -= abs(a[i][k + 1]);
                else
                    ans[i][k] += abs(a[i][k + 1]);
            }
        }
        ll x, y, max = -0xffff;
        for(ll i = 1; i <= n; i++)
        {
            for(ll k = 1; k <= m; k++)
            {
                if(ans[i][k] > max)
                {
                    x = i;
                    y = k;
                    max = ans[i][k];
                }
            }
        }
        cout << x << " " << y << " " << max<<endl;
    }
    return 0;
}
