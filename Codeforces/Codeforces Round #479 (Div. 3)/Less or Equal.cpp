/*
Problem:
Author:QiZhao
Data:2018-03-
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
    int n, k;
    cin >> n >> k;
    vector<ll> v;
    for(int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int count = 0;
    ll x = -0xffff;
    if(k == 0)
    {
        if(v[0] >= 2)
            cout << v[0] - 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    if(k == n)
    {
        /*
        if(v[n - 1] == 1000000000)
            cout << -1 << endl;
        else
            cout << v[n - 1] + 1 << endl;
        */
        cout<<v[n-1]<<endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if( count > k)
        {
            cout << -1 << endl;
            return 0;
        }
        else if(count < k)
        {
            count++;
            x = v[i];
        }
        else if(count == k)
        {
            if(v[i] == x)
            {
                cout << -1 << endl;
                return 0;
            }
            else
            {
                cout << x << endl;
                return 0;
            }
        }
    }
    return 0;
}

