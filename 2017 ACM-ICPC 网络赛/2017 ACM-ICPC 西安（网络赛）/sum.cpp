/*
Problem:
Author:QiZhao
Data:2017-09-
Description:输出0
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=233;

int Length(ll temp)
{
    ll ans=0;
    while(temp)
    {
        ans/=10;
    }
    return ans;
}
int main()
{
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        if(x==1)
            cout<<"89999999999999999999999999"<<endl;
        else
        {
            for(ll i=0;;i++)
            {
                ll ans=0;
                ll temp=i*x;
                ll len=Length(temp);
                while(len--)
                {
                    ans=ans+(temp%10);
                    temp=temp/10;
                }
                if(ans%mod==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}


