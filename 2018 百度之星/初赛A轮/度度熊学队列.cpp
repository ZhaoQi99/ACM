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

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}

vector<deque<int> > vv;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   // cin.sync_with_stdio(false);
    int n, q;
    while(cin >> n >> q)
    {
        vv.clear();
        forn(i, n)
        {
            deque<int> t;
            vv.push_back(t);
        }
        forn(i, q)
        {
            int flag = read();
            if(flag == 1)
            {
                int u, w, val;
                u = read();
                w = read();
                val = read();
                if(w == 0)
                    vv[u - 1].push_front(val);
                else
                    vv[u - 1].push_back(val);
            }
            else if(flag == 2)
            {
                int u, w;
                u = read();
                w = read();
                if(vv[u - 1].empty() == true)
                    cout << -1 << endl;
                else
                {
                    if(w == 0)
                    {
                        cout << vv[u - 1].front() << endl;
                        vv[u - 1].pop_front();
                    }
                    else
                    {
                        cout << vv[u - 1].back() << endl;
                        vv[u - 1].pop_back();
                    }
                }
            }
            else
            {
                int u, v, w;
                u = read();
                v = read();
                w = read();
                if(!vv[v - 1].empty())
                {
                    if(w == 0)
                    {
                        while(!vv[v - 1].empty())
                        {
                            vv[u - 1].push_back(vv[v - 1].front());
                            vv[v - 1].pop_front();
                        }
                        vv[v - 1].clear();
                    }
                    else
                    {
                        while(!vv[v - 1].empty())
                        {
                            vv[u - 1].push_back(vv[v - 1].back());
                            vv[v - 1].pop_back();
                        }
                        vv[v - 1].clear();
                    }
                }
            }
        }
    }
    return 0;
}

