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

const int N = 5e4 + 4; //元素总个数
ll sum[N * 4];
ll a[N];

void build(int k, int l, int r)
{
    sum[k] = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

void change(int k, int l, int r, int x, int v)
//x为原序列的位置,v为增加的值
{
    if(r < x || l > x)
        return;
    if(l == r && l == x)
    {
        sum[k]++;
        return;
    }
    int mid = (l + r) >> 1;
    change(k << 1, l, mid, x, v);
    change(k << 1 | 1, mid + 1, r, x, v);
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
    return;
}

ll query(int k, int l, int r, int x, int y)
{
    if(y < l || x > r)
        return 0;
    if(l >= x && r <= y)
        return sum[k];
    int mid = (l + r) >> 1;
    ll res = 0;
    res += query(k << 1, l, mid, x, y);
    res += query(k << 1 | 1, mid + 1, r, x, y);
    return res;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll summ = 0;
    int n;
    while(cin >> n)
    {
        summ = 0;
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        build(1, 1, n );
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            summ += query(1, 1, n, a[i], n);
            change(1, 1, n, a[i], 0);
        }
        ll ans = summ;
        for(int i = 1; i <= n; i++)
        {
            summ += (n - 1 - 2 * a[i]);
            if(summ < ans)
                ans = summ;
        }
        cout << ans << endl;
    }
    return 0;
}

