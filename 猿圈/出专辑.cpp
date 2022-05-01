/*
Problem:
Author:QiZhao
Data:2018-03-
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
    ll n,s,l;
    cin>>n>>s>>l;
    ll ans=0;
    //计算每张最多几首
    ll num=0;
    ll a=0,b=0,c=0;
    a=l/(s+1);
    b=ll((l-s)/(s+1))+1;
    num=max(a,b);
    if(num%13==0)
        num--;
    //cout<<num<<"da "<<endl;
    ans=ll(n/1.0/num);
    ll sheng=n-ans*num;
    if(sheng==13&&sheng*(s+1)>l-s)
       ans+=2;
    else if(sheng!=13)
        ans++;
    else
        ans++;
    cout<<ans<<endl;
    return 0;
}

