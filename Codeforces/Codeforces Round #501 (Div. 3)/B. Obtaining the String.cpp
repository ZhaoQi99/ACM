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

string s, t;

ll cnt = 0;
vector<int> v;
void swap(int n)
{
    int i = n;
    while(s[i] != t[n])
        i++;
    for(int j = i; j > n; j--)
    {
        char c = s[j];
        s[j] = s[j - 1];
        s[j - 1] = c;
        cnt++;
        v.push_back(j );
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> s;
    cin >> t;
    int a[40];
    int b[40];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; i++)
    {
        a[s[i] - 'a']++;
        b[t[i] - 'a']++;
    }
    for(int i = 0; i < 40; i++)
    {
        //cout<<i<<":"<<a[i]<<","<<b[i]<<endl;
        if(a[i] != b[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
        swap(i);
    cout << cnt << endl;
    vector<int>::iterator t;
    for(t = v.begin(); t != v.end();)
    {
        cout << *t;
        if(++t != v.end())
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}

