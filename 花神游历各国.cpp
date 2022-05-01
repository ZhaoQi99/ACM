/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
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
//区间查询,区间修改
const int N=1e5+5;//元素总个数
ll sum[N*4];
ll a[N];
bool tag[N*4];

void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[l];
        if(sum[k]==0||sum[k]==1ll)
            tag[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
    tag[k]=(tag[k<<1]&tag[k<<1|1]);
}


void change(int k,int l,int r,int x,int y)
{
    if(tag[k])
        return;
    //if(l>=x&&r<=y)
    if(l==r)
    {
        sum[k]=sqrt(sum[k]);
        if(sum[k]==0||sum[k]==1ll)
            tag[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    //pushdown(k,l,r,mid);
    if(x<=mid)
        change(k<<1,l,mid,x,y);
    if(mid<y)
        change(k<<1|1,mid+1,r,x,y);
    sum[k]=sum[k<<1]+sum[k<<1|1];
    tag[k]=(tag[k<<1]&tag[k<<1|1]);
    return;
}

ll query(int k,int l,int r,int x,int y)
{
    if(y<l||x>r)
        return 0;
    if(l>=x&&r<=y)
        return sum[k];
    int mid=(l+r)>>1;
    ll res=0;
    res+=query(k<<1,l,mid,x,y);
    res+=query(k<<1|1,mid+1,r,x,y);
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    ll n,m;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    scanf("%lld",&m);
    for(int i=0;i<m;i++)
    {
        int x,l,r;
        scanf("%d %d %d",&x,&l,&r);
        if(l>r)
            swap(l,r);
        if(x==1)
            printf("%lld\n",query(1,1,n,l,r));
        else
            change(1,1,n,l,r);
    }
    return 0;
}

