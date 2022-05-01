/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
//区间查询,单点修改
const ll N=2e5+5;//元素总个数
ll sum[N*4];
ll a[N];
ll D;

void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=max(sum[k<<1],sum[k<<1|1]);
}

void change(int k,int l,int r,int x,int v)
{
    if(r<x||l>x)
        return;
    if(l==r&&l==x)
    {
        sum[k]=v;
        return;
    }
    int mid=(l+r)>>1;
    change(k<<1,l,mid,x,v);
    change(k<<1|1,mid+1,r,x,v);
    sum[k]=max(sum[k<<1],sum[k<<1|1]);
    return;
}

ll query(int k,int l,int r,int x,int y)
{
    if(y<l||x>r)
        return 0;
    if(l>=x&&r<=y)
        return sum[k];
    int mid=(l+r)>>1;
    return max(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll m;
    cin>>m>>D;
    char s;
    ll t=0,len=0,x;
    build(1,1,N);
    forn(i,m)
    {
        cin>>s>>x;
        if(s=='A')
        {
            change(1,1,N,++len,(x+t)%D);
        }
        else
        {
            t=query(1,1,N,len-x+1,len);
            cout<<t<<endl;
        }
    }
    return 0;
}

