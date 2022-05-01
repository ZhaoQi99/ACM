/*
Problem:k-Factorization
Author:赵旗
Data:2017-04-23
Description:分解
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll n,k,ans=0;
    cin>>n>>k;
    ll a[50];
    if(k==1)
    {
        cout<<n<<" "<<endl;
    }
    else
    {
        for(ll j=0;j<k-1;j++)
        {
            for(ll i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    a[ans++]=i;
                    n/=i;
                    break;
                }
            }
        }
        if(ans==k-1)
        {
            for(ll i=0;i<k-1;i++)
                cout<<a[i]<<" ";
            cout<<n<<" "<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
