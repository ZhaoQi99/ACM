/*
ID: qizhao11
PROG: pprime
LANG: C++11
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool is(ll x)
{
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
ll ans[3000] = {5, 7, 11};

int main( )
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    cin.sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll flag = 3;
    ll temp;
    for(ll i = 1; i <= 9; i += 2)
    {
        for(int j = 0; j <= 9; j++)
        {
            temp = 100 * i + j * 10 + i;
            if(is(temp))
                ans[flag++] = temp;
        }
    }
    for(ll i = 1; i <= 9; i += 2)
    {
        for(ll j = 0; j <= 9; j++)
        {
            for(ll k = 0; k <= 9; k++)
            {
                temp = 10000 * i + i + j * 1000 + j * 10 + k * 100;
                if(is(temp))
                    ans[flag++] = temp;
            }
        }
    }
    for(ll i = 1; i <= 9; i += 2)
    {
        for(ll j = 0; j <= 9; j++)
        {
            for(ll k = 0; k <= 9; k++)
            {
                for(ll m = 0; m <= 9; m++)
                {
                    temp = i * 1000000 + i + j * 100000 + 10 * j + k * 10000 + k * 100 + m * 1000;
                    if(is(temp))
                        ans[flag++] = temp;
                }
            }
        }
    }
    for(ll i = 0; ans[i] <= b; i++)
    {
        if(ans[i] >= a && ans[i] <= b)
            cout << ans[i] << endl;
    }
    return 0;
}

