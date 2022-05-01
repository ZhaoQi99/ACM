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
    int n, m;
    cin >> m >> n;
    int g[250][250];
    memset(g,0x3f,sizeof(g));
    g[0][0]=0;
    for (int i = 1; i <= m ; i++)
    {
        g[i][i - 1] = g[i - 1][i] = 1;
        g[i][i] = 0;
    }
    forn(i, n)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    forn(k,m+1)
    {
        forn(i,m+1)
        {
            forn(j,m+1)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    cout<<g[0][m]<<endl;
    return 0;
}

