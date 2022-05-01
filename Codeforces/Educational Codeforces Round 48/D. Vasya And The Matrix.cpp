/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll flag = 0;
    ll a[n];
    ll b[m];
    forn(i, n)
    {
        cin >> a[i];
        flag ^= a[i];
    }
    forn(i, m)
    {
        cin >> b[i];
        flag ^= b[i];
    }
    if(flag != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i = 1; i < m; i++)
        flag ^= b[i];
    flag ^=a[n-1];
    forn(i, n - 1)
    {
        cout << a[i] << " ";
        forn(j, m - 1)
        {
            cout << 0<<" ";
        }
        cout<<endl;
    }
    cout<<flag<<" ";
    for (int i = 1; i < m; i++)
    {
        cout << b[i];
        if(i == m - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}

