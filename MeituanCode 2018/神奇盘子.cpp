/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>
#define PI 3.1415927
using namespace std;

typedef long long ll;
const double EPS = 1e-8;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    int r;
    int x1, y1, x2, y2;
    double l1, l2, ans1, ans2;
    cin >> r;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    ans1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double pre = 0xffff;
    for(double i = 0; i < 360; i += 1e-5)
    {
        double c = i / 180 * PI;
        double x = r * cos(c);
        double y = r * cos(c);
        double len = sqrt((-x2  - x) * (-x2 - x) + (-y1 - y) * (-y1 - y)) + sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        if(len - pre > EPS)
        {
            break;
        }
        pre = len;
    }
    l1 = pre;
    pre = 0xffff;
    for(double i = 360; i >= 0; i -= 1e-5)
    {
        double c = i / 180 * PI;
        double x = r * cos(c);
        double y = r * cos(c);
        double len = sqrt((-x2  - x) * (-x2 - x) + (-y1 - y) * (-y1 - y)) + sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        if(len - pre > EPS)
        {
            break;
        }
        pre = len;
    }
    l2 = pre;
    double ans = 0;
    ans2 = l1 - l2 > EPS ? l2 : l1;
    ans = ans1 - ans2 > EPS ? ans2 : ans1;
    printf("%.9f\n", ans);
    return 0;
}

