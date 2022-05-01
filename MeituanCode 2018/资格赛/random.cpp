/*
Problem:
Author:QiZhao
Data:2018-05-
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
    int n, m, k, c;
    m = rand() % 6 + 1;
    n = rand() % 500 + 1;
    c = rand() % 500 + 1;
    k = rand() % n + 1;
    cout << n <<" "<< m<<" " << k << " "<< c<<endl;
    for(int i = 0; i < m; i++)
    {
        int w = rand() % 166 + 1;
        cout << w;
        if(i != m - 1)
            cout << " ";
    }
    cout << endl;
    int score[505][505];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            score[i][j] = rand() % 1000 + 1;
        }
    }
    score[rand() % n + 1][rand() % m + 1] = -1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << score[i][j];
            if(j != m - 1)
                cout << " ";
        }
    }
    return 0;
}

