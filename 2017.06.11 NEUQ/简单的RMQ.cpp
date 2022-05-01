//TLE
/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<iostream>
#include<algorithm>
#include<string.h>
typedef long long ll;

using namespace std;
ll a[100005];
ll temp[10005];
int main( )
{
    cin.sync_with_stdio(false);
    ll n,q;
    ll l,r;
    while(cin>>n>>q)
    {
        memset(a,0,sizeof(a));
        for(ll i=0;i<n;i++)
            cin>>a[i];
        while(q--)
        {
            cin>>l>>r;
            memset(temp,0,sizeof(temp));
            ll pos1,pos2,flag;
            ll* p1=lower_bound(a,a+n,l);
            flag=*p1;
            pos1=p1-a;
            ll* p2=upper_bound(a,a+n,r);
            pos2=p2-a;
            ll temp2=0;
            temp[temp2]=1;
            for(ll i=pos1+1;i<pos2;i++)
            {
                if(a[i]==flag)
                    temp[temp2]++;
                else
                {
                    temp[++temp2]++;
                    flag=a[i];
                }
            }
            sort(temp,temp+temp2,greater<ll>());
            cout<<temp[0]<<endl;
        }
        system("pause");
    //}
    return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<cmath>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define N 100005
#define INF 1<<30
using namespace std;

int a[N];
int value[N],cnt[N],num[N],L[N],R[N];
int ST[N][20];
int n,q;
int k;

void make_ST()//对cnt[]预处理
{
    for(int i=1;i<=k;i++)
    {
        ST[i][0]=cnt[i];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;(i+(1<<j)-1)<=n;i++)
        {
            ST[i][j]=Max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
        }
    }
}

int Query(int l,int r)
{

    if(l>r)
        return 0;
    else
    {
        int kk=floor(log2(r-l+1));
        return Max(ST[l][kk],ST[r-(1<<kk)+1][kk]);
    }
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&q);
        k=0;
        value[0]=INF;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=value[k])
            {
                R[k]=i;
                value[++k]=a[i];
                L[k]=i-1;
                cnt[k]=1;
                num[i]=k;
            }
            else
            {
                cnt[k]++;
                num[i]=num[i-1];
            }
        }
        R[k]=n+1;
        make_ST();
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(num[l]==num[r])
            {
                printf("%d\n",r-l+1);
            }
            else
            {
                int tmp=Max(R[num[l]]-l,r-L[num[r]]);
                int ans=Max(tmp,Query(num[l]+1,num[r]-1));
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
*/
