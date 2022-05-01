/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll temp;
ll n,k;

void DFS(int a,int b)
{
    for(int i=0;i<=k;i++)
    {
        if(a>=temp)
        {
            cout<<a<<endl;
            return;
        }
        if(b*i<=k)
            DFS(a*10+i,i);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin>>n>>k;
    temp=pow(10,n-1);
    for(int i=1;i<=k;i++)
        DFS(i,i);
    return 0;
}

