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
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        int a[n];
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        vector<int> v;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i+1; j < n; j++)
            {
                v.push_back(min(a[i], a[j]));
            }
        }
        vector<int>::iterator it=v.end()-k;
        cout<<(*it)<<endl;;
    }
    return 0;
}
