/*
Problem:音乐研究
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. Aint rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int a[1003];
int b[1003];
int main( )
{
    cin.sync_with_stdio(false);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    int sum=1e9,temp,flag;
    for(int i=0;i<=m-n;i++)
    {
        temp=0;
        flag=i;
        for(int k=0;k<n;k++)
        {
            temp+=(b[flag+k]-a[k])*(b[flag+k]-a[k]);
        }
        if(temp<sum)
            sum=temp;
    }
    cout<<sum<<endl;
    return 0;
}
