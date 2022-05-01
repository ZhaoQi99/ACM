/*
Problem:
Author:QiZhao
Data:2018-05-
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
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(temp%2==0)
            temp=temp-1;
        v.push_back(temp);
    }
    vector<ll>::iterator t=v.begin();
    for(;t!=v.end()-1;t++)
    {
        cout<<*t<<" ";
    }
    t=v.end();
    cout<<*(--t)<<endl;
    return 0;
}

