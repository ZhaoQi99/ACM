/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int Query(int y)
{
    cout<<y<<endl;
    fflush(stdout);
    int t;
    cin>>t;
    if(t==-2||t==0)
        exit(0);
    return t;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll m,n;
    cin>>m>>n;
    bool p[n];
    memset(p,true,sizeof(p));
    for(int i=0;i<n;i++)
    {
        int t=Query(1);
        p[i]=t==1;
    }
    ll l=2,r=m;
    for(int j=0;;j++)
    {
        ll y=(l+r)/2;
        int t=Query(y);
        if(p[j%n]==false)
            t*=-1;
        if(t==1)
            l=y+1;
        else
            r=y-1;
    }
    return 0;
}

