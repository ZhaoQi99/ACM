/*
Problem:
Author:赵旗
Data:2017-07-11
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll used[100005];
ll a[100005];
int main( )
{
    cin.sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    ll n;
    ll ans[100005];
    ll temp = 0, temp2 = 0;
    ll out=-0xffff;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        ans[i-1]=0;
        temp=i;
        temp2=0;
        for(ll k = 0;; k++)
        {
            if(!used[a[temp]])
            {
                used[a[temp]]= 1;
                temp = a[temp];
                ans[i-1]++;
            }
            else
                break;
        }
        if(out<ans[i-1])
            out=ans[i-1];
        if(ans[i-1]==n)
            break;
    }
    cout << out << endl;
    return 0;
}
