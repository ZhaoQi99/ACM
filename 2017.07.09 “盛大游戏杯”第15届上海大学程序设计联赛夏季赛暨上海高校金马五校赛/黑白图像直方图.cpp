//WA
/*
Problem:
Author:赵旗
Data:2017-07-09
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    ll m, n;
    while(cin >> m >> n)
    {
        char a[m][n];
        memset(a,0,sizeof(a));
        for(ll i = 0; i < m; i++)
        {
            for(ll j = 0; j < n; j++)
                cin >> a[i][j];
        }
        bool flag=true;
        for(ll i=0;i<n;i++)
        {
            ll ans=0;
            if(i=n-1)
                flag=false;
            for(ll j=0;j<m;j++)
            {
                if(a[j][i]=='1')
                    ans++;
            }
            cout<<ans;
            if(flag==true)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
