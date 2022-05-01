#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

struct stu
{
    ll cheng;
    ll jia;
    stu(ll a, ll b)
    {
        cheng = a;
        jia = b;
    }
};

vector<ll> v;
queue<stu> a;
ll n, k;
ll len = 0;

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
ll kgcd(ll a, ll b)
{
    ll s = 1, c;
    while(a && b)
    {
        if((~a & 1) && (~b & 1))
            a >>= 1, b >>= 1, s <<= 1;
        else if(~a & 1)
            a >>= 1;
        else if(~b & 1)
            b >>= 1;
        else if(a > b)
            a = a - b;
        else
            c = b - a, b = a, a = c;
    }
    if(!a)
        return b * s;
    if(!b)
        return a * s;
}

void solve()
{
    for(ll i = 1; i <= 9; i++)
    {
        stu tt(i, i);
        a.push(tt);
    }
    for(ll i = 0; i < len; i++)
    {
        ll Sizea = a.size();
        for(ll j = 0; j < Sizea; j++)
        {
            stu temp = a.front();
            a.pop();
            for(ll k = 1; k <= 9; k++)
            {
                //ll temp1 = temp.jia * 10 + k;
                if(temp1 > n)
                {
                    return;
                }
                ll t = temp.cheng * k % 998244353;
                v.push_back(t);
                stu tt(t, temp1);
                a.push(tt);
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    clock_t t=clock();
    int sum = 0;
    /*
    for(ll i = 1; i <= n; i++)
    {
        if(i%10==0)
            continue;
        ll a = f(i);
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<ll>());*/
    ll nn = n;
    while(nn != 0)
    {
        len++;
        nn = nn / 10;
    }
    solve();
    ll Size = v.size();
    for(int i = 0; i < Size; i++)
    {
        ll temp = v[i];
        for(int j = 0; j < Size; j++)
        {
            if(kgcd(temp, v[j]) <= k)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;
    clock_t tt=clock();
    cout<<(tt-t)/CLOCKS_PER_SEC;
}
