/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
vector<ll> s;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll temp = 1;
    s.push_back(temp);
    for(ll i = 1;; i++)
    {
        ll temp2 = temp + i + 2;
        //cout << temp2 << endl;
        s.push_back(temp2);
        temp = temp2;
        if(temp > 1e+9)
            break;
    }
    //sort(s.begin(), s.end());
    ll n;
    cin >> n;
    while(n--)
    {
        ll m;
        cin >> m;
        bool flag = true;
        ll a;
        vector<ll> t;
        for(ll i = 0; i < m ; i++)
        {
            cin >> a;
            t.push_back(a);
        }
        sort(t.begin(),t.end());
        a=t[0];
        vector<ll>::iterator result = find( s.begin( ), s.end( ), a);
        //cout<<*result<<endl;
        if(result == s.end())
        {
            flag = false;
        }
        else
        {
            for(ll i = 1; i < m; i++)
            {
                ++result;
                if(t[i] != (*result))
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

