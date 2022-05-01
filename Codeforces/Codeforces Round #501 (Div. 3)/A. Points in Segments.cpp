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
    ll n, m;
    cin >> n >> m;
    bool flag[m + 1];
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        for(int j = l; j <= r; j++)
            flag[j] = true;
    }
    int cnt = 0;
    vector<int> ans;
    for(int i = 1; i <= m; i++)
    {
        if(flag[i] == false)
        {
            cnt++;
            ans.push_back(i);
        }
    }
    if(cnt==0)
    {
        cout<<0<<endl;
        cout<<endl;
        return 0;
    }
    vector<int>::iterator t=ans.begin();
    cout<<cnt<<endl;
    for(;t!=ans.end();)
    {
        cout<<*t;
        if(++t!=ans.end())
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}

