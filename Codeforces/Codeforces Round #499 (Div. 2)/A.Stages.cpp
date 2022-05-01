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
    int n,k;
    cin>>n>>k;
    set<char> str;
    string temp;
    cin>>temp;
    for(int i=0;i<temp.size();i++)
        str.insert(temp[i]);
//    cout<<str<<endl;
    if(k>=14)
        cout<<-1<<endl;
    else if(str.size()<k)
        cout<<-1<<endl;
    else
    {
        int ans=0;
        int flag=0;
        int cnt=0;
        set<char>::iterator t=str.begin();
        for(int i=0;i<str.size();i++,t++)
        {
            if(cnt==k)
                break;
            if((int(*t)-flag)!=1)
            {
                ans+=int(*t)-96;
                //cout<<ans<<endl;
                flag=int(*t);
                cnt++;
            }
        }
        if(cnt==k)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}

