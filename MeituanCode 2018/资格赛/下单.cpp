/*
Problem:
Author:QiZhao
Data:2018-05-27
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu;

ll n, m;
double ans1 = 0;
ll ans2 = 0;
ll flag = 0;
vector<stu> v;
vector<stu> vv;

struct stu
{
    int a;
    int flag;
    stu(int aa, int flagg)
    {
        a = aa;
        flag = flagg;
    }
};
/*
void Dfs(int cha, int value)
{
    if(cha <= 0)
    {
        ans.push_back(ans2 + value);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        Dfs(ans2 - v[i].a, value + v[i].a);
    }
}
*/
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a, flag;
        cin >> a >> flag;
        stu temp(a, flag);
        v.push_back(temp);
        ans2 += a;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        stu temp(a, b);
        vv.push_back(temp);
    }
    //method 1
    for(int i = 0; i < n; i++)
    {
        if(v[i].flag == 1)
            ans1 += v[i].a * 0.8;
        else
            ans1 += v[i].a;
    }
    //method 2
    for(int i = 0; i < m; i++)
    {
        if(ans2 >= vv[i].a)
        {
            if(vv[i].flag > flag)
                flag = vv[i].flag;
        }
    }
    /*
    //coudan
    for(int i = 0; i < m; i++)
    {
        if(vv[i].a > ans2)
        {
            int cha = vv[i].a - ans2;
            Dfs(cha, 0);
        }
    }
    */
    double ans=min(ans1,double(ans2 - flag));
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
/*
3 2
2 0
5 0
6 0
10 2
14 10
*/

