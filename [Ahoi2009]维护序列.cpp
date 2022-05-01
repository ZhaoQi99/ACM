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
typedef unsigned long long ll;
//区间查询,区间修改
const int N=1e5+5;//元素总个数
ll sum[N*4];
ll a[N];
ll add[N*4];
ll mul[N*4];
ll mod;

void build(int k,int l,int r)
{
    add[k]=0;
    mul[k]=1;
    if(l==r)
    {
        sum[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}

void Add(int k,int l,int r,int m,int a)
//区间加值并更新
{
    add[k]=(add[k]*m%mod+a)%mod;
    mul[k]=mul[k]*m%mod;
    sum[k]=(sum[k]*m%mod+(ll)a*(r-l+1)%mod)%mod;
    return;
}

void pushdown(int k,int l,int r,int mid)
//标记下放
{
    if(add[k]==0&&mul[k]==1)
        return;
    Add(k<<1,l,mid,mul[k],add[k]);
    Add(k<<1|1,mid+1,r,mul[k],add[k]);
    add[k]=0;
    mul[k]=1;
}

void change(int k,int l,int r,int x,int y,int m,int a)
//区间加
{
    if(l>=x&&r<=y)
        return Add(k,l,r,m,a);
    int mid=(l+r)>>1;
    pushdown(k,l,r,mid);
    if(x<=mid)
        change(k<<1,l,mid,x,y,m,a);
    if(mid<y)
        change(k<<1|1,mid+1,r,x,y,m,a);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
    return;
}

ll query(int k,int l,int r,int x,int y)
{
    if(y<l||x>r)
        return 0;
    if(l>=x&&r<=y)
        return sum[k]%mod;
    int mid=(l+r)>>1;
    ll res=0;
    pushdown(k,l,r,mid);
    res=query(k<<1,l,mid,x,y)%mod;
    res+=query(k<<1|1,mid+1,r,x,y)%mod;
    return res%mod;
}

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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin>>n>>mod;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    ll m;
    cin>>m;
    while(m--)
    {
        int op,l,r,c;
        cin>>op;
        if(op==1||op==2)
        {
            cin>>l>>r>>c;
            if(op==1)
                change(1,1,n,l,r,c,0);
            else
                change(1,1,n,l,r,1,c);
        }
        else
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}

