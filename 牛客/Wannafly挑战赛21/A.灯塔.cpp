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

struct point
{
    ll x;
    ll y;
};

struct rule1
{
    bool operator() (const point &s1, const point &s2)
    {
        if(s1.x != s2.x)
            return s1.x < s2.x;
        else
            return s1.y < s2.y;
    }
};
struct rule2
{
    bool operator()(const point &s1, const point &s2)
    {
        if(s1.y != s2.y)
            return s1.y < s2.y;
        else
            return s1.x < s2.x;
    }
};

vector<point> v;
vector<point> x1, x2, y11, y22;
bool ans = false;

void JudgeX1()
{
    if(ans == true)
        return;
    vector<point>::iterator t1, t2;
    for(t1 = x1.begin(); t1 != x1.end(); t1++)
    {
        ll temp = t1->y;
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->y <= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->y >= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            ll len = (t2->x) - (t1->x);
            ll flag1 = temp + len;
            ll flag2 = temp - len;
            if(t2->y <= flag1 && t2->y >= flag2)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
    }
}
void JudgeX2()
{
    if(ans == true)
        return;
    vector<point>::iterator t1, t2;
    for(t1 = x2.begin(); t1 != x2.end(); t1++)
    {
        ll temp = t1->y;
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->y <= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->y >= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            ll len = (t1->x) - (t2->x);
            ll flag1 = temp + len;
            ll flag2 = temp - len;
            if(t2->y <= flag1 && t2->y >= flag2)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
    }
}

void JudgeY2()
{
    if(ans == true)
        return;
    vector<point>::iterator t1, t2;
    for(t1 = y22.begin(); t1 != y22.end(); t1++)
    {
        ll temp = t1->x;
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->x <= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->x >= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            ll len = (t1->y) - (t2->y);
            ll flag1 = temp + len;
            ll flag2 = temp - len;
            if(t2->x <= flag1 && t2->x >= flag2)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
    }
}

void JudgeY1()
{
    if(ans == true)
        return;
    vector<point>::iterator t1, t2;
    for(t1 = y11.begin(); t1 != y11.end(); t1++)
    {
        ll temp = t1->x;
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->x <= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            if(t2->x >= temp)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
        for(t2 = v.begin(); t2 != v.end(); t2++)
        {
            ll len =   (t2->y) - (t1->y);
            ll flag1 = temp + len;
            ll flag2 = temp - len;
            if(t2->x <= flag1 && t2->x >= flag2)
                continue;
            else
                break;
        }
        if(t2 == v.end())
        {
            ans = true;
            return;
        }
    }
}
void Judge()
{
    JudgeX1();
    JudgeX2();
    JudgeY1();
    JudgeY2();
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin >> n;
        v.clear();
        x1.clear();
        x2.clear();
        y11.clear();
        y22.clear();
        ans = false;
        for(ll i = 0; i < n; i++)
        {
            point temp;
            cin >> temp.x >> temp.y;
            v.push_back(temp);
        }
        vector<point>::iterator t;
        vector<point>::reverse_iterator  tt;
        sort(v.begin(), v.end(), rule1());
        ll temp = v.begin()->x;
        for(t = v.begin(); t != v.end(); t++)
        {
            if(t->x == temp)
            {
                x1.push_back(*t);
            }
            else
                break;
        }
        temp = v.rbegin()->x;
        for(tt = v.rbegin(); tt != v.rend(); tt++)
        {
            if(tt->x == temp)
            {
                x2.push_back(*tt);
            }
            else
                break;
        }
        sort(v.begin(), v.end(), rule2());
        temp = v.begin()->y;
        for(t = v.begin(); t != v.end(); t++)
        {
            if(t->y == temp)
            {
                y11.push_back(*t);
            }
            else
                break;
        }
        temp = v.rbegin() -> y;
        for(tt = v.rbegin(); tt != v.rend(); tt++)
        {
            if(tt->y == temp)
            {
                y22.push_back(*tt);
            }
            else
                break;
        }
        Judge();
        if(ans == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

