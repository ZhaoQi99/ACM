/*
Problem:风格不统一如何写程序
Author:赵旗
Data:2017-05-03
Description:字符串查找
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
        string a;
        cin>>a;
        ll length=a.size();
        for(ll i=0;i<length;i++)
        {
            if(a[i]>96&&a[i]<123)
                cout<<a[i];
            else
            {
                if(a[i]=='_')
                {
                    cout<<char(a[++i]-32);
                }
                else
                    cout<<"_"<<char(a[i]+32);
            }
        }
        cout<<endl;
    }
    return 0;
}
