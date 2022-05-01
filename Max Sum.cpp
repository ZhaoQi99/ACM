/*
Problem:Max Sum
Author:赵旗
Data:2017-05-01
Description:DP,HDU1003
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[100020];
ll dp[100020];
ll dp2[100020];
int main( )
{
    ll t,temp;
    cin>>t;
    temp=1;
    while(t--)
    {
        ll n;
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        for(ll i=0;i<n;i++)
            cin>>a[i];
        dp[0]=a[0];
        for(ll i=1;i<n;i++)
        {
            dp[i]=a[i]+max(ll(0),dp[i-1]);
            if(dp[i-1]>=0)
                dp2[i]=dp2[i-1];
            else
                dp2[i]=i;
        }
        ll maxsum=dp[0];
        ll e=0;
        for(ll i=1;i<n;i++)
        {
            if(maxsum<dp[i])
            {
                maxsum=dp[i];
                e=i;
            }
        }
        cout<<"Case "<<temp<<":"<<endl;
        cout<<maxsum<<" "<<dp2[e]+1<<" "<<e+1<<endl;
        if(t!=0)
            cout<<endl;
        temp++;
    }
    return 0;
}
