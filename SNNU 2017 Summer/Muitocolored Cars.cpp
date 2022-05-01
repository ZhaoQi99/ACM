/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[1000005];
ll f[1000005];
int main( )
{
    cin.sync_with_stdio(false);
    ll n,k,temp;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    cin>>n>>k;
    f[k]=1;
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        if(a[temp]<a[k])
            f[temp]=1;
        a[temp]++;
        if(a[temp]<a[k])
            f[temp]=1;
    }
    for(ll i=1;i<1000005;i++)
    {
        if(f[i]==0&&a[i]>=a[k])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
