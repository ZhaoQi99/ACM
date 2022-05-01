/*
Problem:KazaQ's Socks
Author:QiZhao
Data:2017-08-07
Description:找规律
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    ll n,k;
    ll flag=0;
    ll ans;
    while(cin>>n>>k)
    {
        flag++;
        if(k<=n)
            ans=k;
        else
        {
            if((k-n)%(n-1)!=0)
                ans=(k-n)%(n-1);
            else
            {
                if((k-n)/(n-1)%2)
                    ans=n-1;
                else
                    ans=n;
            }
        }
        cout<<"Case #"<<flag<<": "<<ans<<endl;
    }
    return 0;
}

