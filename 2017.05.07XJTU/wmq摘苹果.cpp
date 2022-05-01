/*
Problem:wmq摘苹果
Author:赵旗
Data:2017-05-07
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll app[10];
int main( )
{
    ll ans=0;
    for(ll i=0;i<10;i++)
        cin>>app[i];
    ll maxn;
    cin>>maxn;
    for(ll i=0;i<10;i++)
    {
        if(app[i]<=maxn+30)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
