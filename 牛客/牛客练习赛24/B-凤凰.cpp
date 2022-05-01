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
vector<vector<int> > v(1000006);
inline int dfs(int a, int b)
{
    int temp = 1;
    int len=v[a].size();
    forn(i, len)
    {
        if(v[a][i] != b)
            temp += dfs(v[a][i], a);
    }
    return temp;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    forn(i, n - 1)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = -0xffff;
    forn(i, v[1].size())
    {
        ans = max(ans, dfs(v[1][i], 1));
    }
    cout << ans << endl;
    return 0;
}

