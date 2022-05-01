/*
Problem:Not Afraid
Author:赵旗
Data:2017-04-26
Description:暴力
Copyright © 2017 赵旗. All rights reserved.  
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll n,m;
    ll a[10010];
    bool flag;
    cin>>n>>m;
    ll temp=m,ans=0;
    while(temp--)
    {
        ll k;
        cin>>k;
        memset(a,0,sizeof(a[0])*k);
        flag=false;
        for(ll i=0;i<k;i++)
            cin>>a[i];
        for(ll i=0;i<k;i++)
        {
            for(ll j=0;j<k;j++)
            {
                if(a[i]==-a[j])
                {
                    flag=true;
                    break;
                }
            }
            if(flag==true)
            {
                ans++;
                break;
            }
        }
    }
    if(ans==m)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
