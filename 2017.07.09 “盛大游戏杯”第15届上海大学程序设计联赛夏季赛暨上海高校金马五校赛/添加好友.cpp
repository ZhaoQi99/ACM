//TLE
/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long LL;

using namespace std;
long long p = 1000000007;

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i = 1; i <= m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p - 2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main( )
{
    cin.sync_with_stdio(false);
    LL n;
    while(cin >> n)
    {
        LL ans = 0;
        for(LL i = 1; i <= n; i++)
        {
            ans += Lucas(n, i); //可优化
            if(n % 2 == 1 && i == n / 2)
            {
                ans *= 2;
                break;
            }
            if(n % 2 == 0 && i == n / 2 - 1)
            {
                ans *= 2;
                ans += Lucas(n, i / 2);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
