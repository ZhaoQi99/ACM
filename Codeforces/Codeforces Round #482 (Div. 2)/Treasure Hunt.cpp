/*
/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll Count(string t)
{
    ll len = t.length();
    int used[200];
    for(int i = 0; i < 200; i++)
        used[i] = 0;
    for(int i = 0; i < len; i++)
        used[t[i] - 'A']++;
    int ans = -0xffff;
    for(int i = 0; i < 26; i++)
    {
        if(used[i] > ans)
            ans = used[i];
    }
    for(int i = 0; i < 26; i++)
    {
        if(used[i + 32] > ans)
            ans = used[i + 32];
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[4];
    memset(a, 0, sizeof(a));
    string t;
    for(int i = 1; i <= 3; i++)
    {
        cin >> t;
        ll len = t.length();

        a[i] = Count(t);
        if(a[i] == len && n == 1)
            a[i] = len - 1;
        else
            a[i] = (a[i] + n) > len ? len : a[i] + n;
    }

    //cout << a[1] << " " << a[2] << " " << a[3] << endl;
    //Print
    ll temp[4];
    for(int i = 0; i < 3; i++)
        temp[i] = a[i + 1];
    sort(temp, temp + 3);

    if(temp[2] == temp[1])
        cout << "Draw" << endl;

    else
    {
        if(a[1] > max(a[2], a[3]))
            cout << "Kuro" << endl;
        else if(a[2] > max(a[1], a[3]))
            cout << "Shiro" << endl;
        else
            cout << "Katie" << endl;
    }
    return 0;
}

