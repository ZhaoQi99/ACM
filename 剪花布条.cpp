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

//KMP
const int N=1003;
char A[N],B[N];
int P[N],n,m;
//A为主串,B为子串

void pre()
{
    P[1]=0;
    int j=0;
    for(int i=1;i<m;i++)
    {
        while(j>0&&B[j+1]!=B[i+1])
            j=P[j];
        if(B[j+1]==B[i+1])
            j++;
        P[i+1]=j;
    }
}
int ans=0;
int kmp()
{
    ans=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j>0&&B[j+1]!=A[i+1])
            j=P[j];
        if(B[j+1]==A[i+1])
            j++;
        if(j==m)
        {
            ans++;
            j=0;
        }
        //j=P[j];//可以重叠;
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    while(cin>>A+1)
    {
        if(A[1]=='#')
        {
            break;
        }
        cin>>B+1;
        m=strlen(B+1);
        n=strlen(A+1);
        pre();
        kmp();
        cout<<ans<<endl;
    }
    return 0;
}

