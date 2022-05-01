#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define N 1005

int abc[N][105];
int f[N][105];
int h[N];

void Solve()
{
    memset(abc,0,sizeof(abc));
    h[0]=0;h[1]=0;
    abc[0][0]=1;abc[1][0]=1;
    for(int i=2;i<N;i++)
    {
        for(int j=0;j<105;j++)
        {
            abc[i][j]+=abc[i-1][j]+abc[i-2][j];
            if(abc[i][j]>=10)
            {
                abc[i][j]-=10;
                abc[i][j+1]++;
            }
        }
        for(int j=104;j>=0;j--)
        {
            if(abc[i][j])
            {
                h[i]=j;
                break;
            }
        }
    }
}

bool compare1(char *str,int len,int a[],int n)
{
    if(n<len) return true;
    if(n>len) return false;
    for(int i=0;i<n;i++)
    {
        if(str[i]-'0'>a[i]) return true;
        if(str[i]-'0'<a[i]) return false;
    }
    return true;
}

bool compare2(char *str,int len,int a[],int n)
{
    if(n>len) return true;
    if(n<len) return false;
    for(int i=0;i<n;i++)
    {
        if(str[i]-'0'<a[i]) return true;
        if(str[i]-'0'>a[i]) return false;
    }
    return true;
}

char a[105],b[105];

int main()
{
    Solve();
    for(int i=0;i<N;i++)
        for(int j=h[i];j>=0;j--)
            f[i][h[i]-j]=abc[i][j];
    int record1,record2;
    while(cin>>a>>b)
    {
        int len1=strlen(a);
        int len2=strlen(b);
        if(len1==1&&len2==1&&a[0]=='0'&&b[0]=='0') break;
        for(int i=1;i<N;i++)
        {
            if(compare2(a,len1,f[i],h[i]+1))
            {
                record1=i;
                break;
            }
        }
        for(int i=N-1;i>=1;i--)
        {
            if(compare1(b,len2,f[i],h[i]+1))
            {
                record2=i;
                break;
            }
        }
        cout<<record2-record1+1<<endl;
    }
    return 0;
}
