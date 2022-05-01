/*
Problem:
Author:QiZhao
Data:2017-10-
Description:T了....
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll x, y, z;
    ll sum = 0;;
    ll n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        ll temp = 0;
        ll eat = y;
        if(y == 0 && z == 0)
            continue;
        temp += x + y;
        sum += y;
        /*while(temp<=t)
        {
            temp+=x;
            if(temp>=t)
                break;
            eat+=z;
            temp+=eat;
            if(temp>t)
            {
                sum+=t-(temp-eat);
                break;
            }
            else
                sum+=eat;
        }*/
        ll nn = sqrt(2 * t / (z + 1));
        ll tt = nn * (x + y + z) + nn * (nn - 1) / 2 * z;
        ll an=x+y+z+(nn-1)*z;
        for(;; nn++)
        {
            an+=z;
            tt+=an;
            if(tt >= t)
                break;
        }
        nn-=3;
        temp += nn * (x + y + z) + nn * (nn - 1) / 2 * z;
        sum += nn * (y + z) + nn * (nn - 1) / 2 * z;
        eat = y + z + (nn - 1) * z;
        while(temp <= t)
        {
            temp += x;
            if(temp >= t)
                break;
            eat += z;
            temp += eat;
            if(temp >= t)
            {
                sum += t - (temp - eat);
                break;
            }
            else
                sum += eat;
        }
    }
    cout << sum << endl;
    return 0;
}

