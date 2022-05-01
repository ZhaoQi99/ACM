/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    int Q1[n + 1];
    int Q2[n + 1];
    int flag1 = 0, flag2 = 0;
    forn(i, a.length())
    {
        if(a[i] == 'R')
        {
            Q1[++flag1] = i + 1;
        }
        else
        {
            Q2[++flag2] = i + 1;
        }
    }
    while(m--)
    {
        char c;
        int i;
        cin >> c >> i;
        if(c == 'R')
        {
            if(i > flag1)
                cout << -1 << endl;
            else
                cout << Q1[i] << endl;
        }
        else
        {
            if(i > flag2)
                cout << -1 << endl;
            else
                cout << Q2[i] << endl;
        }
    }
    return 0;
}

