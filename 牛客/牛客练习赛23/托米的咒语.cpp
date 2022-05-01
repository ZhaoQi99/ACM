///WA
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
    string str;
    cin>>str;
    ll ans=0;
    if(str.size()<9)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<=str.size()-9;i++)
    {
        int cnt=0;
        bool flag[20];
        memset(flag,false,sizeof(flag));
        int j;
        for(j=i;j<str.size();j++)
        {
            int temp=str[j]-'a';
            if(flag[temp]==false)
            {
                flag[temp]=true;
                cnt++;
            }
            else
                break;
            if(cnt==9)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

