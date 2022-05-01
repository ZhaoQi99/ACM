//TLE case:10%
/*
Problem:
Author:赵旗
Data:2017-06-18
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string a, b;
ll temp = -1;
ll n1, n2;
char* aux;
string s;
ll ans = -1e10;
ll anstemp = 0;
int solve()
{
    string s1;
    s1.resize(2 * s.size() + 2);
    s1[0] = '$';
    s1[1] = '#';
    for (int i = 0; i < (int)s.size(); ++i)
    {
        s1[(i + 1) << 1] = s[i];
        s1[((i + 1) << 1) + 1] = '#';
    }
    vector<int> p(s1.size(), 0);
    int res = 0;
    for (int id = 0, i = 1; i < (int)s1.size(); ++i)
    {
        if (p[id] + id > i) p[i] = min(p[2 * id - i], p[id] + id - i);
        else p[i] = 1;
        while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
        if (i + p[i] > id + p[id]) id = i;
        res = max(res, p[i]);
    }
    return res - 1;
}
int compare();
void fun(int i, int j, int k)
{
    if(k == n1 + n2)
    {
        s = aux;
        compare();
        return;
    }
    if(i < n1)
    {
        aux[k] = a[i];
        fun(i + 1, j, k + 1);
    }
    if(j < n2)
    {
        aux[k] = b[j];
        fun(i, j + 1, k + 1);
    }
    temp++;
}
int compare()
{
    anstemp = solve();
    if(anstemp > ans)
        ans = anstemp;
    return 0;
}
int main( )
{
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        ans = -1e10;
        anstemp = 0;
        temp = 0;
        a = "\0";
        b = "\0";
        cin >> a;
        cin >> b;
        n1 = a.length();
        n2 = b.length();
        aux = new char[n1 + n2 + 1];
        memset(aux, 0, n1 + n2 + 1);
        fun(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
