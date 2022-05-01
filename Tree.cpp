///WA
/*
Problem:
Author:QiZhao
Data:2018-07-
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
const int N = 1e5 + 5;
int Next[N * 2], first[N * 2], go[N * 2], tot;
int Dep[N];
int f[N][21];

int Add(int u, int v)
{
    Next[++tot] = first[u];
    first[u] = tot;
    go[tot] = v;
    Next[++tot] = first[v];
    first[v] = tot;
    go[tot] = u;
}

void dfs(int u, int father)
{
    Dep[u] = Dep[father] + 1;
    for (int i = 0; i <= 19; i++)
        f[u][i + 1] = f[f[u][i ]][i];
    for(int e = first[u]; e; e = Next[e])
    {
        int v = go[e];
        if(v == father)
            continue;
        f[v][0] = u;
        dfs(v, u);
    }
}

int LCA(int x, int y)
{
    if (Dep[x] < Dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (Dep[f[x][i]] >= Dep[y])
            x = f[x][i];
        if (x == y)
            return x;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}

int dist(int x, int y)
{
    return Dep[x] + Dep[y] - 2 * Dep[LCA(x, y)];
}

struct node
{
    int x, y;
    int len;
    node() {}
    node(int xx, int yy, int llen)
    {
        x = xx;
        y = yy;
        len = llen;
    }
};
bool operator <(const node& s1, const node& s2)
{
    return s1.len < s2.len;
}
int changdu[102][102];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    memset(Next, 0, sizeof(Next));
    memset(f, 0, sizeof(f));
    memset(first, 0, sizeof(first));
    memset(go, 0, sizeof(go));
    memset(changdu, 0, sizeof(changdu));
    int n, m;
    cin >> n >> m;
    vector<int> black;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            black.push_back(i);
        }
    }
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        Add(x, y);
    }
    if(m==1)
    {
        cout<<0<<endl;
        return 0;
    }
    dfs(1, 0);
    vector<node> vv;
    for(int i = 0; i < black.size(); i++)
    {
        for(int j = i + 1; j < black.size(); j++)
        {
            int dis = dist(black[i], black[j]);
//            cout << black[i] << ":" << black[j] << "=" << dis << endl;
            changdu[black[i]][black[j]] = dis;
            changdu[black[j]][black[i]] = dis;
            node t(black[i], black[j], dis);
            vv.push_back(t);
        }
    }
    sort(vv.begin(), vv.end());
    set<int> have;
    set<int>::iterator tt;
    int ans = 0;
    for(int i = 0; i < vv.size(); i++)
    {
        //cout<<vv[i].len<<endl;
        if(have.size() >= m)
            break;
        if(have.find(vv[i].x) != have.end())
        {
            int temp = vv[i].y;
            for(int j = 0; j <= n; j++)
            {
                if(have.find(j) != have.end())
                {
                    if(changdu[temp][j] > ans)
                        ans = changdu[temp][j];
                }
            }
            have.insert(temp);
        }
        else if(have.find(vv[i].y) != have.end())
        {
            int temp = vv[i].x;
            for(int j = 0; j <= n; j++)
            {
                if(have.find(j) != have.end())
                {
                    if(changdu[temp][j] > ans)
                        ans = changdu[temp][j];
                }
            }
            have.insert(temp);
        }
        else
        {
            int temp = vv[i].x;
            for(int j = 0; j <= n; j++)
            {
                if(have.find(j) != have.end())
                {
                    if(changdu[temp][j] > ans)
                        ans = changdu[temp][j];
                }
            }
            have.insert(vv[i].x);
            temp = vv[i].y;
            for(int j = 0; j <= n; j++)
            {
                if(have.find(j) != have.end())
                {
                    if(changdu[temp][j] > ans)
                        ans = changdu[temp][j];
                }
            }
            have.insert(vv[i].y);
            if(vv[i].len > ans)
                ans = vv[i].len;
        }
    }
//    for(tt = have.begin(); tt != have.end(); tt++)
//        cout << "have" << *tt << endl;
    cout << ans << endl;
    return 0;
}
/*
6 3
1 1 0 1 1 1
1 2
1 3
1 4
3 5
3 6


*/
