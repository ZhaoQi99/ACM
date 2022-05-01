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

struct stu
{
    ll a;
    ll b;
    stu()
    {
        a=0;b=0;
    }
};

ll n, x;

const unsigned long long  mod=1e+17;

unsigned long long  MAX = 0;

bool operator<(const stu &s1,const stu &s2)
{
    if(s1.a!=s2.a)
        return s1.a<s2.a;
    else
        return s1.b>s2.b;
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
        stu ss[100005];
        cin >> n >> x;
        for(ll i = 0; i < n; i++)
        {
            cin >> ss[i].a;
        }
        for(ll i = 0; i < n; i++)
        {
            cin >> ss[i].b;
        }
        sort(ss,ss+n);
        MAX=x;
        for(ll i=0;i<n;i++)
        {
            MAX=(ss[i].a*MAX+ss[i].b)%mod;
            cout<<MAX<<endl;
        }
        cout<<MAX<<endl;
    }
    return 0;
}

