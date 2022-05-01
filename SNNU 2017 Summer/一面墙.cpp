/*
Problem:一面墙
Author:赵旗
Data:2017-07-11
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    ll n, k, temp, in;
    cin >> n;
    map<int, int> m;
    for(ll i = 0; i < n; i++)
    {
        cin >> k;
        temp = 0;
        for(ll j = 0; j < k; j++)
        {
            cin >> in;
            if(j!=k-1)
            {
            temp += in;
            m[temp]++;
            }
        }
    }
    int max=0;
    int ans;
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;//后面的元素
            ans = it->first;//前面的元素
        }
    }
    cout<<n-max<<endl;
    return 0;
}
