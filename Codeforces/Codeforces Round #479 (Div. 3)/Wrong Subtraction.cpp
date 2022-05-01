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
    string s;
    int k;
    cin>>s>>k;
    while(k--)
    {
        int len=s.length();
        if(s[len-1]=='0')
        {
            s=s.substr(0,len-1);
        }
        else
        {
            int temp=s[len-1];
            s[len-1]=char(temp-1);
        }
        //cout<<s<<endl;
    }
    cout<<s<<endl;
    return 0;
}

