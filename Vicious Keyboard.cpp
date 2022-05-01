/*
Problem: Vicious Keyboard
Author:赵旗
Data:2017-04-24
Description:字符串查找
Method:先整体遍历一遍,查找"VK",并更改为其他字符。然后，再遍历一遍，查找"KK"||"VV",一旦查找到就结束循环.
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll ans=0;
    string str;
    cin>>str;
    for(ll i=1;i<str.size();i++)//查找"VK"
    {
        if(str[i-1]=='V'&&str[i]=='K')
        {
            ans++;
            str[i-1]=str[i]=0;
        }
    }
    for(ll i=1;i<str.size();i++)//查找"VV"||"KK"
    {
        if(str[i-1]=='V'&&str[i]=='V')
        {
            ans++;
            break;
        }
        if(str[i-1]=='K'&&str[i]=='K')
        {
            ans++;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
