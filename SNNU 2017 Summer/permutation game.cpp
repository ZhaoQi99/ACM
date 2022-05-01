/*
Problem:permutation game
Author:赵旗
Data:2017-07-10
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll used[105];
ll a[105], r[105];
bool fun(ll temp)
{
    for(ll i=0;used[i]!=0;i++)
    {
        if(used[i]==temp)
            return true;
    }
    return false;
}
int main( )
{
    cin.sync_with_stdio(false);
    memset(r, 0, sizeof(r));
    memset(used, 0, sizeof(used));
    ll m, n;
    ll temp2=0;
    cin >> n >> m;
    for(ll i = 0; i < m; i++)
        cin >> a[i];
    for(ll i = 0; i < m - 1; i++)
    {
        ll temp = a[i + 1] - a[i];
        if(temp < 0 || temp == 0)
            temp= temp + n;

        if(r[a[i]] != 0)
        {
            if(temp!=r[a[i]])
            {
                cout << "-1" << endl;
                return 0;
            }
        }
        else
        {
            if(fun(temp))
            {
                cout << "-1" << endl;
                return 0;
            }
            else
            {
                r[a[i]] = temp;
                used[temp2++] = r[a[i]];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(r[i]==0)
        {
            for(ll k=1;k<=n;k++)
            {
                if(!fun(k))
                {
                    r[i]=k;
                    used[temp2++]=r[i];
                    break;
                }
            }
        }
    }
    for(ll i=1;i<=n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
