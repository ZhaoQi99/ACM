/*
Problem:
Author:QiZhao
Data:2017-09-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5e4+4;//元素总个数
ll sum[N*4];
ll a[N];

void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}

void change(int k,int l,int r,int x,int v)
//x为原序列的位置,v为增加的值
{
    if(r<x||l>x)
        return;
    if(l==r&&l==x)
    {
        sum[k]+=v;
        return;
    }
    int mid=(l+r)>>1;
    change(k<<1,l,mid,x,v);
    change(k<<1|1,mid+1,r,x,v);
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
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        string s;
        cout<<"Case "<<i<<":"<<endl;
        while(cin>>s)
        {
            int x,y;
            if(s[0]=='E')
                break;
            else if(s[0]=='A')
            {
                cin>>x>>y;
                change(1,1,n,x,y);
            }
            else if(s[0]=='S')
            {
                cin>>x>>y;
                change(1,1,n,x,-y);
            }
            else
            {
                cin>>x>>y;
                cout<<query(1,1,n,x,y)<<endl;
            }
        }
    }
    return 0;
}

