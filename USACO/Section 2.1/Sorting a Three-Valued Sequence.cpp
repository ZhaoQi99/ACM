/*
ID: qizhao11
TASK: sort3
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    cin.sync_with_stdio(false);
    int a = 0, b = 0, c = 0;
    int n;
    cin >> n;
    int s[n + 2];
    int r[n + 2];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        r[i] = s[i];
    }
    sort(r, r + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s[i] != r[i] && s[j] != r[j] && s[i] == r[j] && s[j] == r[i])
            {
                s[i] = r[i];
                s[j] = r[j];
                ans++;
            }
        }
    }
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        if(r[i] != s[i])
            temp++;
    }
    ans += temp / 3 * 2;
    cout << ans << endl;
    return 0;
}

