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

ll a[300][300];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            cin>>a[n][m];

    return 0;
}

