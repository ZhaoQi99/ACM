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

int IsPrime(int n)
{
    for(int i=2; i<=sqrt(1.0*n); ++i)
        if(n%i == 0)
            return 0;
    return 1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    ll ans[]={2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317};
    for(ll j=1;j<=t;j++)
    {
        string s;
        cin>>s;
        int len=s.length();
        if(len==1||len==2||len==3)
        {
            ll n=0;
            for(int i=0;i<s.length();i++)
                n=n*10+(s[i]-'0');
           // cout<<n<<endl;
            ll flag=0;
            for(int i=0;i<19;i++)
            {
                if(ans[i]<=n)
                {
                    flag=ans[i];
                }
                else
                {
                    break;
                }
            }
            cout<<"Case #"<<j<<": "<<flag<<endl;
        }
        else
            cout<<"Case #"<<j<<": "<<317<<endl;
    }
    return 0;
}

