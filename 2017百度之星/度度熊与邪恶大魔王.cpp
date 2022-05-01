/*
Problem:度度熊与邪恶大魔王
Author:QiZhao
Data:2017-07-
Description:DP，完全背包
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1020;
const ll INF=0x3f3f3f3f;

ll num[maxn][12];//防御值为j，生命值为i的怪物的个数
ll dp[1020][15];//对于生命值为i，防御值为j的怪物所消耗的最小水晶数
struct skill
{
    ll hit;
    ll price;
} a[maxn];
ll best[maxn];//攻击力为i时，消耗的最少水晶数。

ll min(ll a,ll b)
{
    if(a>b)
        return b;
    else
        return a;
    }

void complete_packet(int k, int p)//p为攻击力，k为消耗水晶数
{
    for (int b = 0; b <= 10; ++b)
    {
        if (b >= p)
        {
            continue;
        }
        else
        {
            int d = p - b;
            //血量小于攻击
            for (int a = 1; a <= d; ++a)
            {
                dp[a][b] = min(dp[a][b], k);
            }
            //血量大于攻击
            for (int a = d + 1; a <= 1000; ++a)
            {
                dp[a][b] = min(dp[a][b], dp[a - d][b] + k);
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    ll n, m;
    ll x, y;
    ll /*max_hp = -0xffff,*/ max_def = -INF, max_hit = -INF;
    while(cin >> n >> m)
    {
        max_def = -INF, max_hit = -INF;
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        memset(best, -1, sizeof(best));
        memset(dp, 0, sizeof(dp));
        for(ll i = 0; i < n; i++)
        {
            cin >> x >> y;
            num[x][y]++;
            //if(x >= max_hp)
            //max_hp = x;
            if(y >= max_def)
                max_def = y;
        }
        ll flag = 0;
        for(ll i = 0; i < m; i++)
        {
            cin >> x >> y;
            if(best[y] == -1)
            {
                a[flag].hit = y;
                a[flag].price = x;
                best[y] = x;
                if(a[flag].hit > max_hit)
                    max_hit = a[flag].hit;
                flag++;
            }
            else
            {
                if(x < best[y])
                    best[y] = x;
            }
        }
        ll ans = 0;
        ll temp = 0; //记录已处理怪物个数，优化时间
        if(max_def >= max_hit)
            cout << "-1" << endl;
        else
        {
            for (int i = 0; i <= 1010; ++i)//初始化DP
            {
                for (int j = 0; j <= 10; ++j)
                {
                    if (i == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = INF;
                    }
                }
            }
            for(int i=0;i<flag;i++)
                complete_packet(best[a[i].hit],a[i].hit);
            for(ll i = 0; i < 1002; i++)
            {
                if(temp == n)//优化时间
                    break;
                for(ll j = 0; j < 12; j++)
                {
                    if(num[i][j] != 0)
                    {
                        temp += num[i][j];
                        ans += dp[i][j]*num[i][j];
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

