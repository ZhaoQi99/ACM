/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n,m,q;
    cin>>n>>m>>q;
    char a[n+1],b[m];
    cin>>a+1;
    cin>>b;
    int pre[n+1];
    int temp[n+1];
    memset(pre,0,sizeof(pre));
    for (int i = 1; i <= n-m+1; i++)
    {
        temp[i]=1;
        forn(j,m)
        {
            if(a[i+j]!=b[j])
            {
                temp[i]=0;
                break;
            }
        }
        pre[i]=pre[i-1]+temp[i];
    }
    forn(i,q)
    {
        int l,r;
        cin>>l>>r;
        r-=m-1;
        if(r<l)
            cout<<0<<endl;
        else
            cout<<pre[r]-pre[l-1]<<endl;
    }
    return 0;
}

