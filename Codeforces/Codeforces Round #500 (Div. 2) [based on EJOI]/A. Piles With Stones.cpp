/*
Problem:
Author:QiZhao
Data:2018-07-
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
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        sum1+=a;
    }
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        sum2+=a;
    }
    if(sum2>sum1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}

