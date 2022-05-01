/*
Problem:Mike and palindrome
Author:赵旗
Data:2017-04-24
Description:注意输入是回文串的情况
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll temp=0;
    string str;
    cin>>str;
    for(ll i=0;i<str.size()/2;i++)
    {
        if(str[i]!=str[str.size()-i-1])
            temp++;
    }
    if(temp!=1&&temp!=0)
        cout<<"No"<<endl;
    else
    {
        if((temp==0&&str.size()%2==1)||temp==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
