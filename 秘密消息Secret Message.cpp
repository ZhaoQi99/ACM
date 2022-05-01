/*
Problem:
Author:QiZhao
Data:2018-11-07
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
const int N = 500005;
const int Z = 2;
int ch[N][Z];
bool bo[N];
int tot = 1;

int sum[N];
void Clear()
{
    memset(ch, 0, sizeof(ch));
    memset(bo, false, sizeof(bo));
    memset(sum, 0, sizeof(sum));
    tot = 1;
}

void insert(char *s)
{
    int len = strlen(s);
    int u = 1;
    for(int i = 0; i < len; i++)
    {
        int c = s[i] - '0';
        if(!ch[u][c])
        {
            ch[u][c] = ++tot;
        }
        u = ch[u][c];
        sum[u]++;
    }
    bo[u]=true;
}

int find(char *s)
{
    int len = strlen(s);
    int res = 0;
    int u = 1;
    for(int i = 0; i < len; i++)
    {
        int c = s[i] - '0';
        if(!ch[u][c])
            return res;
        u = ch[u][c];
        res += bo[u];
    }
    return res + sum[u] - bo[u];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Clear();
    char s[10004];
    int temp;
    int num;
    forn(i, n)
    {
        cin >> num;
        forn(j, num)
        {
            cin >> temp;
            s[j] = temp == 1 ? '1' : '0';
        }
        //cout << s << endl;
        insert(s);
        memset(s,'\0',sizeof(s));
    }
    forn(i, m)
    {
        cin >> num;
        forn(j, num)
        {
            cin >> temp;
            s[j] = temp == 1 ? '1' : '0';
        }
        int ans = find(s);
        memset(s,'\0',sizeof(s));
        cout << ans << endl;
    }
    return 0;
}

