/*
Problem:
Author:QiZhao
Data:2018-07-
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
    int n,m;
    cin>>n>>m;
    int arr[102];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        arr[a]++;
    }
    if(n>m)
        cout<<0<<endl;
    else
    {
        int MAX=-0xffff;
        /*
        for(int i=0;i<101;i++)
        {
            if(arr[i]>MAX)
                MAX=arr[i];
        }
        MAX=max(MAX,m/n);
        */
        int ans=0;
        bool flag=false;
        for(int i=100;i>0;i--)
        {
            if(flag==true)
                break;
            int cnt=0;
            for(int j=0;j<101;j++)
            {
                if(arr[j]>=i)
                {
                    cnt+=static_cast<int>(arr[j]/i);
                }
                if(cnt>=n)
                {
                    ans=i;
                    flag=true;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

