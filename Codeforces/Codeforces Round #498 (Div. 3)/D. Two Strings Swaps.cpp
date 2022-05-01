/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    char a[n + 1], b[n + 1];
    cin >> a + 1;
    cin >> b + 1;
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        map<char, int> m;
        m.clear();
        int temp = n - i + 1;
        m[a[i]]++;
        m[b[i]]++;
        m[a[temp]]++;
        m[b[temp]]++;
        int s = m.size();
        switch(s)
        {
        case 4:
            ans += 2;
            break;
        case 3:
            ans = ans + 1 + (a[i] == a[temp]);
            break;
        case 2:
            ans += m[a[i]] != 2;
            break;
        }
    }
    if(n % 2 == 1 && a[n / 2 + 1] != b[n / 2 + 1])
        ans++;
    cout << ans << endl;
    return 0;
}

