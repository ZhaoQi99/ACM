/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long M = 1000000007;
const int MAXL = 1000000;
int Q(int n, int t, int a[])
{
    cout<<"t:"<<t<<endl;
    if(n < 0)
        return t;
    return (Q(n - 1, t, a) + Q(n - 1, (t * a[n]) % M, a)) % M;
}

int a[MAXL];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] %= M;
        }
        cout << Q(n - 1, 1, a) << endl;
    }
    return 0;
}

