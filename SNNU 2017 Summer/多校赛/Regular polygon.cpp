/*
Problem:Regular polygon
Author:QiZhao
Data:2017-08-09
Description:组合数学
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point
{
    ll x;
    ll y;
} a[505];
bool vis[1000][1000];

bool cmp(point &a, point &b)
{
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
int main()
{
    cin.sync_with_stdio(false);
    ll t;
    while(cin >> t)
    {
        memset(a, 0, sizeof(a));
        memset(vis, false, sizeof(vis));
        for(ll i = 0; i < t; i++)
        {
            cin >> a[i].x >> a[i].y;
            a[i].x += 100;
            a[i].y += 100;
            vis[a[i].x][a[i].y] = true;
        }
        ll ans = 0;
        sort(a, a + t, cmp);
        for(ll i = 0; i < t; i++)
        {
            vis[a[i].x][a[i].y] = false;
            //for(ll m = i+1; m < t; m++)
            for(int k = a[i].x; k < 202; k++)
            {
                for(int p = a[i].y+1; p < 202; p++)
                {
                    //if(vis[a[m].x][a[m].y])
                    if(vis[k][p])
                    {
                        ll xx = a[i].x - k;
                        ll yy = a[i].y - p;
                        ll temp1 = a[i].x - yy;
                        ll temp2 = a[i].y + xx;
                        ll temp3 = a[i].x - yy - xx;
                        ll temp4 = a[i].y + xx - yy;
                        if(vis[temp1][temp2] && vis[temp3][temp4])
                            ans++;
                    }
                }
            }
            vis[a[i].x][a[i].y] = true;
        }
        cout << ans << endl;
    }
    return 0;
}

