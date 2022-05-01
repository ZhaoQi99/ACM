/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[10000];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    int flag=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n-1;i>0;i--)
    {
        if(a[i]>=a[i+1])
        {
            flag=i;
            break;
        }
    }
    for(int j=1;j<=flag;j++)
        cout<<a[j]<<" ";
    return 0;
}

