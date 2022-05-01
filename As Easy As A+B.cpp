/*
Problem:As Easy As A+B(HDU 1040)
Author:赵旗
Data:2017-06-10
Description:排序
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int a[10000];
int main( )
{
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<" ";
        cout<<a[n-1]<<endl;
    }
    return 0;
}
