/*
Problem:
Author:QiZhao
Data:2018-07-
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
    ll a[200005];
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll flag1 = 0;
    ll flag2 = n - 1;
    ll ans = 0;
    ll sum1 = a[flag1], sum3 = a[flag2];
    while(flag1 < flag2)
    {
        if(sum1 < sum3)
        {
            flag1++;
            sum1 += a[flag1];
        }
        else if(sum1 > sum3)
        {
            flag2--;
            sum3 += a[flag2];
        }
        else
        {
            ans = sum1;
            if(a[flag1 ] < a[flag2])
            {
                flag1++;
                sum1 += a[flag1];
            }
            else
            {
                flag2--;
                sum3 += a[flag2];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

