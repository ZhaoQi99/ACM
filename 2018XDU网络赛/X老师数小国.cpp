/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans=0;
void  dfs(int dep,int x,int y,int n)
{
    if(x==n)
    {
        ans=dep;
        return ;
    }
    if(n-x<y|x>n|y>n)
        return ;
    dfs(dep+1,x+y,y,n);
    dfs(dep+1,2*x,x,n);
    return ;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        dfs(0,1,1,n);
        cout<<ans<<endl;
    }
    return 0;
}

