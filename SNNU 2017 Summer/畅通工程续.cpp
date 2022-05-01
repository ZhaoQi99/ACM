/*
Problem:
Author:QiZhao
Data:2017-07-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX=1e20;

ll f[220][220];
ll dist[5000],s[5000];
ll n, m;
ll a, b, c;
ll st, e;

void djikstra()
{
    ll i,w,j,min,u;
    for (i=0;i<n;i++)
    {
        dist[i]=f[st][i];
        s[i]=0;
    }
     s[st]=1;
     dist[st]=0;
     for (i=0;i<n;i++)
     {
        min=MAX;
        u=st;
        for (j=0;j<n;j++)
            if (!s[j]&&dist[j]<min)
             min=dist[u=j];
        s[u]=1;
        for (w=0;w<n;w++)
            if (!s[w]&&dist[u]+f[u][w]<dist[w]&&f[u][w]<MAX)
                dist[w]=dist[u]+f[u][w];
     }
}
int main()
{
    cin.sync_with_stdio(false);
    while(cin >> n >> m)
    {
        for(ll i = 0; i < n; i++)
            for(ll k = 0; k < n; k++)
                f[i][k]=MAX;
        for(ll i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            if(c < f[a][b])
                f[a][b] = f[b][a] = c;
        }
        cin >> st >> e;
        djikstra();
        if(dist[e]==MAX)
            cout << "-1" << endl;
        else
            cout << dist[e] << endl;
        memset(f,0,sizeof(f));
        memset(dist,0,sizeof(dist));
    }
    return 0;
}

