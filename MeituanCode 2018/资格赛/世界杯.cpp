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

double ba[17];
double si[17];
double banjue[17];
double jue[17];
double p[17][17];

double fun2(int a, int b, int x)
{
    double ans = 0;
    for(int i = a; i <= b; i++)
        ans += si[i] * p[x][i];
    return ans;
}
double fun(int a, int b, int x)
{
    double ans = 0;
    for(int i = a; i <= b; i++)
        ans += banjue[i] * p[x][i];
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    for(int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++)
            cin >> p[i][j];
    }

    for(int i = 1; i <= 16; i++)
    {
        if(i % 2 == 1)
            ba[i] = p[i][i + 1];
        else
            ba[i] = p[i][i - 1];
    }
    for(int i = 1; i <= 16; i++)
    {
        if(i % 4 == 1)
            si[i] = ba[i] * (ba[i + 2] * p[i][i + 2] + ba[i + 3] * p[i][i + 3]);
        if(i % 4 == 2)
            si[i] = ba[i] * (ba[i + 1] * p[i][i + 1] + ba[i + 2] * p[i][i + 2]);
        if(i % 4 == 3)
            si[i] = ba[i] * (ba[i - 2] * p[i][i - 2] + ba[i - 1] * p[i][i - 1]);
        if(i % 4 == 0)
            si[i] = ba[i] * (ba[i - 2] * p[i][i - 2] + ba[i - 3] * p[i][i - 3]);
    }
    for(int i = 1; i <= 16; i++)
    {
        if(i <= 4)
            banjue[i] = si[i] * fun2(5, 8,i);
        else if(i <= 8)
            banjue[i] = si[i] * fun2(1, 4,i);
        else if(i <= 12)
            banjue[i] = si[i] * fun2(13, 16,i);
        else
            banjue[i] = si[i] * fun2(9, 12,i);
    }
    for(int i = 1; i <= 16; i++)
    {
        if(i <= 8)
            jue[i] = banjue[i] * fun(9, 16, i);
        else
            jue[i] = banjue[i] * fun(1, 8, i);
    }
    for(int i = 1; i < 16; i++)
        cout << fixed << setprecision(10) << jue[i] << " ";
    cout << fixed << setprecision(10) << jue[16] << endl;
    return 0;
}

