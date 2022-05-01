/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    return 0;
}

