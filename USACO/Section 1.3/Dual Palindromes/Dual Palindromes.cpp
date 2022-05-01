/*
ID: qizhao11
PROG: dualpal
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX=300;


void change(int x,int base,char s[])
{
    char temp[30];
    memset(temp,'\0',sizeof(temp));
    for(int i=0;x!=0;i++)
    {
        int t=x%base;
        x/=base;
        if(t>9)
            temp[i]=t%10+'A';
        else
            temp[i]='0'+t;
    }
    int len=strlen(temp);
    for(int i=0;i<len;i++)
        s[i]=temp[len-1-i];
    return;
}

bool ispal(char s[])
{
    int len=strlen(s);
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-1-i])
            return false;
    }
    return true;
}

bool isdual(int flag)
{
    char temp[10004];
    int cnt=0;
    for(int i=2;i<=10;i++)
    {
        memset(temp, '\0', sizeof(temp));
        change(flag,i,temp);
        if(ispal(temp))
            cnt++;
        if(cnt==2)
            return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(false);
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n,s;
    cin>>n>>s;
    int cnt=0;
    int flag=++s;
    while(cnt!=n)
    {
        if(isdual(flag))
        {
            cnt++;
            cout<<flag<<endl;
        }
        flag++;
    }
    return 0;
}

