/*
Problem:
Author:QiZhao
Data:2017-08-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
ll ans[1000006];

int main()
{
    cin.sync_with_stdio(false);
    ll n,a,b,k;
    ll temp=0;
    ll flag=0;
    while(cin>>n>>a>>b>>k)
    {
        cin>>s;
        temp=0;
        flag=0;
        memset(ans,0,sizeof(ans));
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                temp++;
                if(temp==b)
                {
                    ans[flag++]=i+1;
                    temp=0;
                }
            }
            else
                temp=0;
        }
        cout<<flag-a+1<<endl;
        cout<<ans[0];
        for(int i=1;i<flag-a+1;i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}

