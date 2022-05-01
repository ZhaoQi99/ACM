/*
ID: qizhao11
PROG: milk2
LANG: C++11
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct m
{
    ll l;
    ll r;
};

struct rule
{
    bool operator()(const m &s1,const m &s2)
    {
        if(s1.l<=s2.l)
        {
            if(s1.l<s2.l)
                return true;
            else
                return s1.r<=s2.r;
        }
        else
            return false;
    }
};

ll ans1[5005];
ll ans2[5005];
ll flag1=1,flag2=0;
int main( )
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    cin.sync_with_stdio(false);
    struct m a[5005];
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a,a+n,rule());
    ans1[0]=a[0].r-a[0].l;
    ll b=a[0].l;
    ll c=a[0].r;
    for(ll i=1;i<n;i++)
    {
        if(a[i].r<=c)
            continue;
        if(a[i].l<=c)
            c=a[i].r;
        else
        {
            ans1[flag1++]=c-b;
            ans2[flag2++]=a[i].l-c;
            b=a[i].l;
            c=a[i].r;
        }
    }
    sort(ans1,ans1+flag1,greater<ll>());
    sort(ans2,ans2+flag2,greater<ll>());
    cout<<ans1[0]<<" "<<ans2[0]<<endl;
    return 0;
}
