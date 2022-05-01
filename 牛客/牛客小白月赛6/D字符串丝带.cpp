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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    char s[n];
    scanf("%s",s);
    /*
    int dp[n+1][26];
    memset(dp,0,sizeof(dp));
    dp[0][s[0]-'a']++;
    for(int i=1;i<n;i++)
    {
        forn(j,26)
        {
            dp[i][j]=dp[i-1][j];
        }
        dp[i][s[i]-'a']++;
    }
    forn(i,m)
    {
        ll t;
        cin>>t;
        t--;
        cout<<dp[t][s[t]-'a']<<endl;
    }
    */

    int cnt[26];
    int ans[n];
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    forn(i,n)
    {
        cnt[s[i]-'a']++;
        ans[i]=cnt[s[i]-'a'];
    }
    forn(i,m)
    {
        int temp;
        temp=read();
        temp--;
        printf("%d\n",ans[temp]);
    }
    return 0;
}
