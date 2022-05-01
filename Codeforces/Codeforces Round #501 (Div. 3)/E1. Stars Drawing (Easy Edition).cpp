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

const int maxn = 1005;
char g[maxn][maxn];
bool tag[maxn][maxn];
int n, m;

struct stu
{
    int row;
    int col;
    int cen;
    stu(int a, int b, int c)
    {
        row = a;
        col = b;
        cen = c;
    }
};
vector<stu> ans;

bool check()
{
    forn(i, n )
    {
        forn(j, m)
        {
            if(tag[i + 1][j + 1] == false && g[i + 1][j + 1] == '*')
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    memset(tag, false, sizeof(tag));
    forn(i, n )
    {
        forn(j, m )
        {
            cin >> g[i + 1][j + 1];
        }
    }
    ans.clear();
    forn(i, n )
    {
        forn(j, m )
        {
            if(g[i + 1][j + 1] == '*')
            {
                int left = 1, right = 1, top = 1, bottom = 1;
                int Size = 0;
                while(g[i + 1][j + 1 - left] == '*' && j + 1 - left >= 1)
                    left++;
                while(g[i + 1][j + 1 + right] == '*' && j + 1 + right <= m)
                    right++;
                while(g[i + 1 - top][j + 1 ] == '*' && i + 1  - top >= 1)
                    top++;
                while(g[i + 1 + bottom][j + 1] == '*' && i + 1 + bottom <= n)
                    bottom++;
                // cout<<left<<":"<<right<<":"<<top<<":"<<bottom<<endl;
                Size = min(min(left - 1, right - 1), min(top - 1, bottom - 1));
                if(Size > 0)
                {
                    forn(k, Size + 1)
                    {
                        tag[i + 1][j + 1 + k] = true;
                        tag[i + 1][j + 1 - k] = true;
                        tag[i + 1 + k][j + 1] = true;
                        tag[i + 1 - k][j + 1] = true;
                    }
                    stu temp(i + 1, j + 1, Size);
                    ans.push_back(temp);
                    //cout << i + 1 << j + 1 << Size << endl;
                }
            }
        }
    }

    bool flag = check();
    if(flag == false)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<stu>::iterator t;
    cout << ans.size() << endl;
    for(t = ans.begin(); t != ans.end(); t++)
    {
        cout << t->row << " " << t->col << " " << t->cen << endl;
    }
    return 0;
}

