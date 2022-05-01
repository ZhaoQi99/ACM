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
char Map[55][55];
int N,M;
int si,sj;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    bool flag = false;
    while(t--)
    {
        cin >> N >> M;
        flag = false;
        memset(Map, 0, sizeof(Map));
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        //si行
        for(int i = 1; i <=M; i++)
        {
            if(Map[si][i] == '#')
            {
                flag = true;
                break;
            }
        }
        //sj列
        for(int i = 1; i <=N; i++)
        {
            if(Map[i][sj] == '#')
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
            cout << -1 << endl;
        else
            cout << N + M - 2 << endl;
    }
    return 0;
}

