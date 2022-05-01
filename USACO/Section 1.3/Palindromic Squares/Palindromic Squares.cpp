/*
ID: qizhao11
PROG: palsquare
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

int main()
{
    cin.sync_with_stdio(false);
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int m;
    cin>>m;
    for(int i=1;i<=MAX;i++)
    {
        char ans1[30];
        char ans2[30];
        memset(ans1,'\0',sizeof(ans1));
        change(i*i,m,ans1);
        if(ispal(ans1))
        {
            memset(ans2,'\0',sizeof(ans2));
            change(i,m,ans2);
            cout<<ans2<<" "<<ans1<<endl;
        }
    }
    return 0;
}

