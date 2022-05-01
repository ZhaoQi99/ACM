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
vector<vector<int> > v(50005) ;
int len[50005];
int ans;

int dfs(int id)
{
    int temp = 0;
    forn(i, v[id].size())
    {
        temp = max(temp, len[v[id][i]] + dfs(v[id][i]));
    }
    return temp;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    memset(len, 0, sizeof(len));
    forn(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[b].push_back(a);
        len[a] = c;
    }
    ans=0;
    forn(i,n)
    {
        int temp=dfs(i+1);
        if(temp>ans)
            ans=temp;
    }
    cout << ans << endl;
    return 0;
}

