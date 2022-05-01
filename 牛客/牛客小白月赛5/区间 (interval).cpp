///RE
/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
#define LL long long
int a[N];
LL sum[4 * N], add[4 * N];
void update(int x)
{
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void build(int cur, int x, int y)
{
    add[cur] = 0;
    int mid = (x + y) / 2, ls = cur << 1, rs = cur << 1 | 1;
    if(x == y)
    {
        sum[cur] = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    update(cur);
}
void pushdown(int cur, int x, int y)
{
    int mid = (x + y) / 2, ls = cur << 1, rs = cur << 1 | 1;
    if(add[cur] != 0)
    {
        add[ls] += add[cur];
        add[rs] += add[cur];
        sum[ls] += (mid - x + 1) * add[cur];
        sum[rs] += (y - mid) * add[cur];
        add[cur] = 0;
    }
}
void change(int cur, int x, int y, int s, int t, int v)
{
    int mid = (x + y) / 2, ls = cur << 1, rs = cur << 1 | 1;
    if(x >= s && y <= t)
    {
        sum[cur] += (y - x + 1) * v;
        add[cur] += v;
        return;
    }
    pushdown(cur, x, y);
    if(mid >= s)
        change(ls, x, mid, s, t, v);
    if(mid < t)
        change(rs, mid + 1, y, s, t, v);
    update(cur);
}
void query(int cur, int x, int y, int s, int t, LL &ans)
{
    int mid = (x + y) / 2, ls = cur << 1, rs = cur << 1 | 1;
    if(x >= s && y <= t)
    {
        ans += sum[cur];
        return;
    }
    pushdown(cur, x, y);
    if(mid >= s)
        query(ls, x, mid, s, t, ans);
    if(mid < t)
        query(rs, mid + 1, y, s, t, ans);
}
int main()
{
    int q, n, x, y, z;
    int c;
scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        build(1, 1, n);
        for(int i = 1; i <= q; i++)
        {
            cin >> c;
            if(c == 1)
            {
                scanf("%d%d%d", &x, &y, &z);
                change(1, 1, n, x, y, -z);
            }
            else
            {
                scanf("%d%d%d", &x, &y, &z);
                change(1, 1, n, x, y, z);
            }
        }
    scanf("%d%d", &x, &y);
    LL ans = 0;
    query(1, 1, n, x, y, ans);
    printf("%lld\n", ans);
    return 0;
}
