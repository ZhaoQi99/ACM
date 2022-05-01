/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n,k,s;
    cin>>n>>k>>s;
    if(k>s||(n-1)*k<s)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    ll now=1;
    while(k--)
    {
        ll temp=0;
        if(s-(k-1)>n-1)
            temp=n-1;
        else
        {
            if(k==0)
                temp=s;
            else
            {
                if(now==n)
                    now=n-1;
                else if(now==n-1)
                    now=n;
                else if(now==1)
                    now=2;
                else
                    now=1;
                s--;
                temp=0;
            }
        }
        s-=temp;
        if(now-temp<=0)
            now+=temp;
        else
            now-=temp;
        cout<<now;
        if(k==0)
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}

