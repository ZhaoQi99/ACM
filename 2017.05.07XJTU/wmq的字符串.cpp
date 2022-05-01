//TLE.
/*
Problem:wmq的字符串
Author:赵旗
Data:2017-05-07
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int main( )
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        char a[100005];
        memset(a,0,sizeof(a));
        cin>>a;
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            char c,d;
            cin>>c>>d;
            for(ll j=0;j<strlen(a);j++)
            {
                if(a[j]==c)
                    a[j]=d;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
