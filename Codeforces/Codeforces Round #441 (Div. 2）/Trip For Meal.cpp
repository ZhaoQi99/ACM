/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    ll a, b, c;
    ll ans = 0;
    cin >> n;
    cin >> a >> b >> c;
    n--;
    if(n == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
        if(a <= b && a <= c)
            ans = n * a;
        else if(b <= a && b <= c)
            ans = n * b;
        else if(c <= a && c <= b)
        {
            ans+=min(a,b);
            n--;
            ans+=n*c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
