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
    ll n,m;
    cin>>n>>m;
    vector<ll> v;
    ll all=0;
    ll jian=0;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        all+=a;
        jian+=b;
        v.push_back(a-b);
    }
    if(jian>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll cha=all-m;
    sort(v.begin(),v.end(),greater<ll>());
    vector<ll>::iterator t;
    ll ans=0;
    ll temp=0;
    for(t=v.begin();t!=v.end();t++)
    {
        if(temp>=cha)
            break;
        temp+=*t;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

