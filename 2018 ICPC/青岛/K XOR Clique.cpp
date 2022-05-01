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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        int flag[33];
        memset(flag, 0, sizeof(flag));
        forn(i, n)
        {
            cin >> a[i];
            for(int j = 31; j >=0; j--)
            {
                //cout<<(a[i] & (1 << j))<<endl;
                if(a[i] & (1 << j))
                {
                    flag[j]++;
                    break;
                }
            }
        }
        ll ans=0;
        forn(i,33)
        {
            if(flag[i]>ans)
                ans=flag[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
