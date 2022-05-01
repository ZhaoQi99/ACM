/*
Problem:补提交卡
Author:赵旗
Data:2017-05-03
Description:贪心，枚举
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
        ll n,m,ans=0,temp;
        ll a[105];
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(ll i=1;i<n+1;i++)
            cin>>a[i];
        a[0]=0;
        sort(a,a+n);
        if(m>=n)
            ans=100;
        else
        {
            for(ll i=0;i<n;i++)
            {
                if(i+m+1>n+1)//i+m+1=n时允许执行
                    break;
                temp=a[i+m+1]-a[i]-1;
                if(temp>ans)
                    ans=temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
