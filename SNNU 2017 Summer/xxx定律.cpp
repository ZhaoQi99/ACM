/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    ll ans=0;
    ll s;
    while(cin>>s)
    {
        ans=0;
        if(s==0)
            return 0;
        while(s!=1)
        {
            if(s%2==0)
                s/=2;
            else
            {
                s=3*s+1;
                s/=2;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
