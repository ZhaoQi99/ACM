/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu
{
    int x;
    int y;
    int z;
    int a;
    int b;
    double c;
};
bool operator <(const stu& s1, const stu&s2)
{
    if(s1.a != s2.a)
        return s1.a < s2.a;
    else if(s1.b != s2.b)
        return s1.b < s2.b;
    else
        return s1.c < s2.c;
}
int sta[505][505];
ll n, m, k;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(sta, 0, sizeof(sta));
    vector<stu> in;
    for(int i = 0; i < k; i++)
    {
        stu temp;
        cin >> temp.x >> temp.y >> temp.z;
        string s;
        cin >> s;
        temp.a = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
        temp.b = (int)(s[3] - '0') * 10 + (int)(s[4] - '0');
        temp.c = (int)(s[6] - '0') * 10 + (int)(s[7] - '0')
                 + 0.1 * (s[9] - '0') + 0.01 * (s[10] - '0') + 0.001 * (s[11] - '0');
        in.push_back(temp);
    }
    sort(in.begin(), in.end());
    vector<stu>::iterator t;
    int MAX = -0xffff;
    int ans[505][505];
    memset(ans, 0, sizeof(ans));
    ll temp = 0;
    for(t = in.begin(); t != in.end(); t++)
    {
        if(t->z == 0)
        {
            if(sta[t->x][t->y] == 0)
                temp++;
            sta[t->x][t->y]++;
        }
        if(t->z == 1)
        {
            sta[t->x][t->y]--;
            if(sta[t->x][t->y] == 0)
                temp--;
        }
        if(temp >= MAX)
        {
            MAX = temp;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(sta[i][j] != 0)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}

