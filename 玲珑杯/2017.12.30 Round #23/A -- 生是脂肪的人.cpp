/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
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
    int s, l, b, i;
    int ans[] = {7, 1, 4, 2, 8, 5};
    while(n--)
    {
        char str[100000];
        cin >> str;
        s = 6;
        l = strlen(str);
        b = 0;
        if(str[0] == '-')
            cout << "0" << endl;
        else
        {
            for(i = 0; i < l; i++)
                b = (b * 10 + (str[i] - '0') % s) % s;
            cout << ans[b] << endl;
        }
    }
    return 0;
}
