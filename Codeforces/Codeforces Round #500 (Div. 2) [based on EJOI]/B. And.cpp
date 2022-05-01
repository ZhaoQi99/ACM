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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    set<int> s1,s3;
    multiset<int> s2;
    int n, x;
    cin >> n >> x;
    int flag[100005];
    memset(flag,0,sizeof(flag));
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s1.insert(a);
        ll temp = a & x;
        s2.insert(temp);
        s3.insert(temp);
        if(temp==a)
            flag[a]=true;
        //cout<<(a&x)<<endl;
    }
    if(s1.size() != n)
    {
        cout << 0 << endl;
        return 0;
    }
    set<int>::iterator t = s1.begin();
    for(; t != s1.end(); t++)
    {
        if(s2.count(*t)>=(1+flag[*t]))
        {
            cout<<1<<endl;
            return 0;
        }
    }
    if(s3.size()!=n)
    {
        cout<<2<<endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}

