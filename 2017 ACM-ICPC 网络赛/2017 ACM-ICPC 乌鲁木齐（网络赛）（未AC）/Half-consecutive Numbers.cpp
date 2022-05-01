/*
Problem:
Author:QiZhao
Data:2017-09-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    cin.sync_with_stdio(false);
    ll num[10000]={ 0,1, 36, 1225, 41616, 1413721, 48024900, 1631432881, 55420693056, 1882672131025, 63955431761796,
    2172602007770041, 73804512832419600, 2507180834294496361,};
    ll temp[10000];
    for(ll i=0;i<14;i++)
    {
        temp[i]=sqrt(2*num[i]);//第几项
    }
    ll t;
    ll n;
    /*for(ll i=0;i<14;i++)
        cout<<temp[i]<<endl;*/
    while(cin>>t)
    {
        while(cin>>n)
        {
            for(ll i=0;i<14;i++)
            {
                if(num[i]<=n&&num[i+1]>=n)
                {
                    cout<<temp[i+1]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}

