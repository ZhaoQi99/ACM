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
ll fun(ll m)
{
    ll sum=0;
    while(m)
    {
        sum += m / 5;
        m = m / 5;
    }
    return sum;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);

    ll m;
    cin >> m;
    ll sum = 0;
    ll flag=0;
    ll i;
    for(i=0;i<=m;i+=5)
    {
        flag++;
        sum+=flag*5;
    }
    sum-=(i-m)*flag;
    cout << sum << endl;
    return 0;
}

