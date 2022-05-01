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

const int N=1e5+4;//元素总个数
ll sum[N*4];
int a[N];
int add[N*4];

void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}

void Add(int k,int l,int r,int v)
//标记下放
{
    add[k]=v;
    sum[k]=(ll)v*(r-l+1);
}

void pushdown(int k,int l,int r,int mid)
{
    if(add[k]==0)
        return;
    Add(k<<1,l,mid,add[k]);
    Add(k<<1|1,mid+1,r,add[k]);
    add[k]=0;
}

void change(int k,int l,int r,int x,int y,int v)
//区间加
{
    if(l>=x&&r<=y)
        return Add(k,l,r,v);
    int mid=(l+r)>>1;
    pushdown(k,l,r,mid);
    if(x<=mid)
        change(k<<1,l,mid,x,y,v);
    if(mid<y)
        change(k<<1|1,mid+1,r,x,y,v);
    sum[k]=sum[k<<1]+sum[k<<1|1];
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
    res=query(k<<1,l,mid,x,y);
    res+=query(k<<1|1,mid+1,r,x,y);
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        memset(add,0,sizeof(add));
        int n,m;
        scanf("%d",&n);
        build(1,1,n);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            change(1,1,n,x,y,z);
        }
        printf("Case %d: The total value of the hook is %lld.\n",k,sum[1]);
       // cout<<"Case "<<k<<": The total value of the hook is "<<sum[1]<<"."<<endl;
    }
    return 0;
}

