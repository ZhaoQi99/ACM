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

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}

struct stu
{
    string x;
    ll v, k;
    stu()
    {
        v = 0;
        k = 0;
    }
};
bool ff[10004][256];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll num = 0;
        stu task[10004];
        memset(ff, false, sizeof(ff));
        for(int i = 1 ; i <= n ; i++)
        {
            string s;
            ll v, k;
            cin >> s;
            if(s == "add" )
            {
                task[i].x = s;
                cin >> k;
                task[i].k = k;
            }
            else
            {
                cin >> v >> k;
                task[i].x = s;
                task[i].v = v;
                task[i].k = k;
            }
        }
        ll flag = 1;
        bool exit = false;
        while(true)
        {
            string ss = task[flag].x;
            ll vv = task[flag].v;
            ll kk = task[flag].k;
            if(ss == "add")
            {
                if(ff[flag][num] == true)
                {
                    exit = true;
                    break;
                }
                ff[flag][num] = true;
                num += task[flag].k;
                num = num % 256;
                flag++;
            }
            else if(ss == "beq")
            {
                if(ff[flag][num] == true)
                {
                    exit = true;
                    break;
                }
                ff[flag][num] = true;
                if(vv == num)
                    flag = kk;
                else
                    flag++;
            }
            else if(ss == "bne")
            {
                if(ff[flag][num] == true)
                {
                    exit = true;
                    break;
                }
                ff[flag][num] = true;
                if(vv != num)
                    flag = kk;
                else
                    flag++;
            }
            else if(ss == "blt")
            {
                if(ff[flag][num] == true)
                {
                    exit = true;
                    break;
                }
                ff[flag][num] = true;
                if(vv > num)
                    flag = kk;
                else
                    flag++;
            }
            else if(ss == "bgt")
            {
                if(ff[flag][num] == true)
                {
                    exit = true;
                    break;
                }
                ff[flag][num] = true;
                if(vv < num)
                    flag = kk;
                else
                    flag++;
            }
            if(exit == true)
                break;
            if(flag == n + 1)
                break;
        }
        if(exit == true)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}

