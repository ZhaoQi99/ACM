#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n % 10 == 0)
            return 0;
        ans = (ans * (n % 10)) % 998244353;
        n = n / 10;
    }
    return ans;
}

ll gcd(ll x, ll y)
{
    ll z = y;
    while(x % y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    int sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll a = f(i);
        if(a==0)
            continue;
        for(ll j = 1; j <= n; j++)
        {
            ll b = f(j);
            if(b!=0)
            {
                if(gcd(a, b) <= k)
                    sum++;
            }
        }
    }
    cout << sum << endl;
}