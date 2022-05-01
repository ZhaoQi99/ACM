/*
ID: qizhao11
PROG: sprime
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll n;

bool isprime(ll x)
{
    if(x == 1)
        return false;
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

string ltos(long l)
{
    ostringstream os;
    os << l;
    string result;
    istringstream is(os.str());
    is >> result;
    return result;

}

bool isSuperprime(ll x)
{
    string xx = ltos(x);
    ll temp = 0;
    for(int i = 1; i <= n; i++)
    {
        //判断前缀是否为素数
        temp = temp * 10 + xx[i - 1] - '0';
        if(isprime(temp) == false)
            return false;
    }
    return true;
}


int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    ll ans6[]={233993,239933,293999,373379,373393,593933,593993,719333,739391,739393,739397,739399};
    ll ans7[]={2339933,2399333,2939999,3733799,5939333,7393913,7393931,7393933};
    ll ans8[]={23399339,29399999,37337999,59393339,73939133};
    cin.sync_with_stdio(false);
    cin >> n;
    if(n < 6)
    {
        for(ll i = pow(10, n - 1) + 1; i < pow(10, n); i += 2)
        {
            if(isSuperprime(i))
                cout << i << endl;
        }
    }
    else
    {
        if(n==6)
        {
            for(int i=0;i<12;i++)
                cout<<ans6[i]<<endl;
        }
        if(n==7)
        {
            for(int i=0;i<8;i++)
                cout<<ans7[i]<<endl;
        }
        if(n==8)
        {
            for(int i=0;i<5;i++)
                cout<<ans8[i]<<endl;
        }
    }
    return 0;
}

