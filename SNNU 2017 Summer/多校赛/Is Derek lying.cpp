/*
Problem:Is Derek lying?
Author:QiZhao
Data:2017-08-07
Description:思维题
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, x, y;
        string a, b;
        ll temp=0;
        bool flag=true;
        cin >> n >> x >> y;
        cin >> a;
        cin >>b;
        for(ll i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                temp++;
        }
        ll temp2=x+y;
        ll temp3=2*n-temp;
        if(temp2>temp3)
            flag=false;
        if(abs(x-y)>temp)
            flag=false;
        if(flag)
            cout<<"Not lying"<<endl;
        else
            cout<<"Lying"<<endl;
    }
    return 0;
}

