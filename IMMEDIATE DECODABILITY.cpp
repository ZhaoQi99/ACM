/*
Problem:IMMEDIATE DECODABILITY(POJ 1056)
Author:QiZhao
Data:2018-11-06
Description:字典树
Copyright  2018 QiZhao. All rights reserved.
*/
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

const int N=1e6+5;
const int Z=2;
int ch[N][Z];
bool bo[N];
int tot=1;

void Clear()
{
    memset(ch,0,sizeof(ch));
    memset(bo,false,sizeof(bo));
    tot=1;
}

bool insert(char *s)
{
    int len=strlen(s);
    int u=1;
    bool flag=false;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'0';
        if(!ch[u][c])
        {
            ch[u][c]=++tot;
        }
        else if(i==len-1)
            flag=true;
        u=ch[u][c];
        if(bo[u])
            flag=true;
    }
    bo[u]=true;
    return flag;
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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    char s[50];
    Clear();
    bool ans=false;
    int cnt=1;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='9')
        {
            if(ans)
                cout<<"Set "<<cnt<<" is not immediately decodable"<<endl;
            else
                cout<<"Set "<<cnt<<" is immediately decodable"<<endl;
            cnt++;
            Clear();
            ans=false;
            continue;
        }
        if(insert(s))
            ans=true;
    }
    return 0;
}

