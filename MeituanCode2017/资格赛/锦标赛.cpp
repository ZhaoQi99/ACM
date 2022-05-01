/*
Problem:
Author:赵旗
Data:2017-06-15
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    ll n,temp,flag,sum=1;
    cin>>n;
    cin>>flag;
    for(ll i=0;i<n-1;i++)
    {
        cin>>temp;
        if(temp<=flag)
            ++sum;
    }
    sum=static_cast<ll>(log(sum)/log(2));
    cout<<sum<<endl;
    return 0;
}
