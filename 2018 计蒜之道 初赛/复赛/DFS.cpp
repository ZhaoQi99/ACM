/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100005];
ll b[100005];
ll n, x;
bool used[100005];

unsigned long long  MAX = 0;

void dfs(int dep,int value)
{
    cout<<dep<<":"<<value<<endl;
    if(dep==n)
    {
        if(value>MAX)
        {
            MAX=value;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(used[i]==false)
        {
            used[i]=true;
            dfs(dep+1,a[i]*value+b[i]);
            used[i]=false;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        MAX=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(used,false,sizeof(used));
        cin >> n >> x;
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        dfs(0,x);
        cout<<MAX<<endl;
    }
    return 0;
}
