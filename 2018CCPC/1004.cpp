/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef unsigned long long ll;
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
    //cin.sync_with_stdio(false);
    ll t;
    scanf("%llu",&t);
    while(t--)
    {
        ll a,n;
        scanf("%llu %llu",&n,&a);
        if(n==0||n>2)
            printf("-1 -1\n");
        else if(n==1)
            printf("%llu %llu\n",a,2*a);
        else if(a%2==1)
        {
            ll nn=a/2;
            ll b=2*nn*nn+2*nn;
            ll c=2*nn*nn+2*nn+1;
            printf("%llu %llu\n",b,c);
        }
        else
        {
            ll nn=a/2;
            ll b=nn*nn-1;
            ll c=nn*nn+1;
            printf("%llu %llu\n",b,c);
        }
    }
    return 0;
}

