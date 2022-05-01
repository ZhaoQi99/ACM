/*
Problem:Crossword solving
Author:ÕÔÆì
Data:2017-07-09
Description:字符串
Copyright  2017 ÕÔÆì. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    ll index=-0xffff,ans=0xffff;
    for(ll i=0;i<m-n+1;i++)
    {
        k=0;
        for(ll j=0;j<n;j++)
        {
            if(s[j]!=t[i+j])
                k++;
        }
        if(k<ans)
        {
            ans=k;
            index=i;
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<n;i++)
    {
        if(t[index+i]!=s[i])
            cout<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}
