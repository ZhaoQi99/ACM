/*
Problem:[HNOI2004]L语言
Author:QiZhao
Data:2018-11-06
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
const int N=1e5+5;
const int Z=26;
int ch[N][Z];
bool bo[N];
int tot=1;

const int M=1050000;
bool ff[M];
int ans;
void Clear()
{
    memset(ch,0,sizeof(ch));
    memset(bo,false,sizeof(bo));
    tot=1;
}

void insert(char *s)
{
    int len=strlen(s);
    int u=1;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c])
        {
            ch[u][c]=++tot;
        }
        u=ch[u][c];
    }
    bo[u]=true;
}

bool find(char *s)
{
    int len=strlen(s);
    int u=1;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[u][c])
            return false;
        u=ch[u][c];
    }
    return true;
}

void solve(string s)
{
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(ff[i]||i==0)
        {
            int lon=1;
            int j=1;
            j=ch[j][s[i]-'a'];
            for(;i+lon<=len && j;++lon)
            {
                if(bo[j])
                    ff[i+lon]=true;
                j=ch[j][s[i+lon]-'a'];
            }
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string s;
    char ss[20];
    Clear();
    forn(i,n)
    {
        cin>>ss;
        insert(ss);
    }
    forn(i,m)
    {
        memset(ff,false,sizeof(ff));
        cin>>s;
        ans=0;
        solve(s);
        for(int i=M;i>=0;i--)
        {
            if(ff[i])
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

