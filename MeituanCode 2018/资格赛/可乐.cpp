/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    double ans=-0xffff;
    int flag=0;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        double  temp=a*m/(n*1.0)+b*(n-m)/(n*1.0);
        if(temp>=ans)
        {
         ans=temp;
         flag=i;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(i==flag)
            cout<<n;
        else
            cout<<0;
        if(i!=k-1)
            cout<<" ";
    }
    cout<<endl;
    return 0;
}

