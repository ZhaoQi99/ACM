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

vector<vector<int> > v(200005);
int ans[200005];
int num[2000005];
int index[200005];

int cnt=0;
int dfs(int id)
{
    index[id]=cnt;
    ans[cnt++]=id;
    int numm=1;
    for(int i=0;i<v[id].size();i++)
    {
        numm+=dfs(v[id][i]);
    }
    num[id]=numm;
    return numm;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    memset(ans, 0, sizeof(ans));
    memset(index, 0, sizeof(ans));
    memset(num, 0, sizeof(ans));
    forn(i, n-1)
    {
        int temp;
        cin >> temp;
        v[temp].push_back(i+2);
    }
    dfs(1);
    while(q--)
    {
        int u, k;
        cin>>u>>k;
        if(k > num[u])
            cout << -1 << endl;
        else
            cout << ans[index[u]+k-1] << endl;
    }
    return 0;
}

