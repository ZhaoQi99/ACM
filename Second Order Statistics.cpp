/*
Problem:Second Order Statistics
Author:赵旗
Data:2017-05-01
Description:sort,CF22A
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll t;
    ll a[110];
    cin>>t;
    for(ll i=0;i<t;i++)
        cin>>a[i];
    sort(a,a+t);
    ll ans=a[0];
    ll i=0,temp=0;
    for(ll i=0;i<t;i++)
    {
        if(a[i]!=ans)
        {
            ans=a[i];
            temp=1;
            break;
        }
    }
    if(temp==1)
        cout<<ans<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
