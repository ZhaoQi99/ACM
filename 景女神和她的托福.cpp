/*
Problem:.景女神和她的托福
Author:赵旗
Data:2017-05-11
Description:西大17校赛G
Copyright  2017 赵旗. All rights reserved.
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
typedef long long ll;

using namespace std;
string str;
ll n,m;
int fun(char c);
int main( )
{
    while(cin>>n>>m)
    {
        getchar();
        getline(cin,str);
        ll ans;
        ans=max(fun('a'),fun('b'));
        cout<<ans<<endl;
    }
    return 0;
}

int fun(char c)//c是被改变的
{
    int l=0,r=0,ans=0,temp=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]==c)
        {
            if(temp<m)
            {
                temp++;
                r++;
            }
            else
            {
                while(l<=r&&str[l]!=c)
                    l++;
                r++;
                l++;
            }
        }
        else
            r++;
        ans=max(ans,r-l);
    }
    return ans;
}
