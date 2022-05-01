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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        double m,n;
        cin>>m>>n;
        printf("%.6f\n",m/n);
    }
    return 0;
}

