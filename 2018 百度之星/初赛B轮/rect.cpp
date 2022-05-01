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
    int x;
    int y;
};

bool operator <(const stu&s1, const stu&s2)
{
    if(s1.x != s2.x)
        return s1.x < s2.x;
    return s1.y < s2.y;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        int mx, my, n;
        cin >> mx >> my >> n;
        vector<stu> v;
        forn(i, n)
        {
            stu temp;
            cin >> temp.x >> temp.y;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        int a[n][4];
        forn(i, n)
        {
            a[i][0] = v[i].x;
            a[i][1] = mx - v[i].x;
            a[i][2] = v[i].y;
            a[i][3] = my - v[i].y;
        }
        int ans = 0xffff;
        for(int i = 1; i <= my; i++)
        {
            for(int k = 1; k <= i; k++)
            {
                int temp = 0;
                forn(j, n)
                {
                    if(v[j].y <= i)
                    {
                        if(v[j].y > k)
                            temp += min(a[j][0], a[j][1]);
                        else
                            temp += min(min(a[j][0], a[j][1]), a[j][2]);
                    }
                    else
                    {
                        temp += a[i][3];
                    }
                }
                cout << temp << endl;
                ans = min(temp, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

