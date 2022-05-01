/*
Problem:继续xxx定律
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[505];
ll flag[1000000];
ll ans[505];
int main( )
{
    cin.sync_with_stdio(false);
    ll n;
    while(cin >> n)
    {
        memset(flag, 0, sizeof(flag));
        ll x;
        if(n == 0)
            return 0;
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        for(ll i = 0; i < n; i++)
        {
            x = a[i];
            if(!flag[a[i]])
            {
                while(x != 1)
                {
                    if(x % 2 == 0)
                    {
                        x /= 2;
                        flag[x] = 1;
                    }
                    else
                    {
                        x = 3 * x + 1;
                        x /= 2;
                        flag[x] = 1;
                    }
                }
            }
        }
        ll temp=0;
        for(ll i=0;i<n;i++)
        {
            if(flag[a[i]]==0)
                ans[temp++]=a[i];
        }
        for(ll i=temp-1;i!=0;i--)
            cout<<ans[i]<<" ";
        cout<<ans[0]<<endl;
    }
    return 0;
}
