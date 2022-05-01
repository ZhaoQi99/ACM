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
    int n;
    cin >> n;
    int t = sqrt(n);
    for(int i = n ; i > 0; i -= t)
    {
        for(int j = max(i - t + 1,1) ; j <= i; j++)
            cout << j << " ";
    }
    return 0;
}

