/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a[1003];
    int b[1003];
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
            flag = true;

    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if(b[i] == 1)
            flag = true;
    }
    if(flag == true)
    {
        cout << -1 << endl;
    }
    else
    {

        double ans = 0.0;
        ans = m * 1.0 / ((b[1] - 1) * 1.0);
        for(int i = 2 * n; i >= 3; i--)
        {
            if(i % 2 == 0)
                ans = (ans * a[i / 2] + m) / ((a[i / 2] - 1) * 1.0);
            else
                ans = (ans * b[i / 2 + 1] + m) / ((b[i / 2 + 1] - 1) * 1.0);
        }
        ans = (ans * a[1] + m) / ((a[1] - 1) * 1.0);
        printf("%.10f\n", ans);
    }
    return 0;
}

