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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    int a[]={0,100,50,20,10,5,2,1};
    int b[]={0,50,20,10,5,2,1};
    while(t--)
    {
        ll aa,bb;
        cin>>aa>>bb;
        ll ans1[10];
        ll ans2[10];
        memset(ans1,0,sizeof(ans1));
        memset(ans2,0,sizeof(ans2));
        for(int i=1;i<=7;i++)
        {
            ans1[i]=aa/a[i];
            aa=aa-a[i]*ans1[i];
        }
        for(int i=1;i<=6;i++)
        {
            ans2[i]=bb/b[i];
            bb=bb-b[i]*ans2[i];
        }
        for(int i=1;i<=7;i++)
            cout<<ans1[i]<<" ";
        for(int i=1;i<=6;i++)
        {
            cout<<ans2[i];
            if(i!=6)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}

