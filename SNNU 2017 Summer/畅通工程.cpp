/*
Problem:
Author:QiZhao
Data:2017-07-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N=5000;
ll f[N];

ll find(ll x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

void merge(ll a,ll b)
{
    ll x,y;
    x=find(f[a]);
    y=find(f[b]);
    if(x!=y)
        f[x]=y;
}

int main()
{
    cin.sync_with_stdio(false);
    ll n,m,a,b;
    ll ans=0;
    while(1)
    {
        cin>>n;
        ans=0;
        if(n==0)
            break;
        for(ll i=1;i<=n;i++)
            f[i]=i;
        cin>>m;
        for(ll i=1;i<=m;i++)
        {
            cin>>a>>b;
            merge(a,b);
        }
        for(ll i=1;i<=n;i++)
        {
            if(find(i)==i)
                ans++;
        }
        cout<<ans-1<<endl;
        memset(f,0,sizeof(a));
    }
    return 0;
}

