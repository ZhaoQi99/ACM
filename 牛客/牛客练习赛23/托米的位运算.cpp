/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin >> n;
    bool a[n][32];
    bool tag[32];//有0
    ll in[n];
    memset(tag, false, sizeof(tag));
    for(ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> in[i];
        temp = in[i];
        for(int j = 0; j < 32; j++)
        {
            int flag;
            if(((temp >> j) & 1) == 0)
            {
                flag = 0;
                tag[j] = true;
            }
            else
                flag = 1;
            a[i][j] = flag;
        }
    }
    vector<int> wei;
    for(int i = 31; i >= 0; i--)
    {
        bool flag = false;
        for(int j = i - 1; j >= 0; j--)
        {
            if(tag[j] == false)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
            continue;
        else//后面的位不能全0
            wei.push_back(i);
    }
    vector<ll> ans;
    for(int j = 0; j < wei.size(); j++)
    {
        ans.clear();
        int v = wei[j];
        for(int i = 0; i < n; i++)
        {
            if(a[i][v] != false)
                ans.push_back(in[i]);
        }
        ///务必注意
        if(v == 0)
            break;
        ///务必注意
        ll And = (1 << wei[j]) - 1;
        for(int i = 0; i < ans.size(); i++)
            And = And & ans[i];
        if(And == 0)
            break;
    }
    cout << ans.size() << endl;
    vector<ll>::iterator t = ans.begin();
    for(; t != ans.end();)
    {
        cout << *t;
        if(++t != ans.end())
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}

