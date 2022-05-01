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
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll ans=0;
    for(int j=0;j<32;j++)
    {
        //统计0,1个数
        ll cnt1=0,cnt2=0;
        for(int i = 0; i < n; i++)
        {
            if(a[i]&(1<<j))
                cnt1++;
            else
                cnt2++;
        }
        ans+=cnt1*cnt2;
    }
    cout<<ans<<endl;
    return 0;
}

