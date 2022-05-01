/*
Problem:手机短号
Author:赵旗
Data:2017-05-04
Description:水题
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll t;
    cin>>t;
    while(t--)
    {
        string num;
        cin>>num;
        cout<<6;
        for(ll i=num.length()-5;i<num.length();i++)
            cout<<num[i];
        cout<<endl;
    }
    return 0;
}
