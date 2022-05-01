/*
Problem:
Author:QiZhao
Data:2017-09-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node
{
    ll day;
    ll wait;
    bool control=true;
};

int main()
{
    cin.sync_with_stdio(false);
    ll n,m;
    while(cin>>n>>m)
    {
        struct Node p[1003];
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            p[i].day=i;
            p[i].wait=temp;
        }
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++)
        {
            ll temp;
            cin>>temp;
            p[temp].control=false;
        }
        int ans1[2]={0xffff,0xffff};
        int ans_len=0xffff;//answer
        int ans_temp=0xffff;
        ll left,right;
        for(ll i=0;i<n;i++)
        {
            ll temp=m;
            ans_temp=0xffff;
            if(p[i].control==true)
            {
                temp--;
                for(ll j=i+1;j<n;j++)
                {
                    if(p[j].control==true)
                    {
                        temp--;
                        if(p[i].wait+p[j].wait<=ans_temp)
                        {
                            left=p[i].day;
                            right=p[j].day;
                            ans_temp=p[i].wait+p[j].wait;
                        }
                    }
                    if(temp==0)
                        break;
                }
            }
            if(ans_temp<ans_len)//The final answer
            {
                ans1[0]=left;
                ans1[1]=right;
                ans_len=ans_temp;
            }
        }
        cout<<ans1[0]<<" "<<ans1[1]<<endl;
    }
    return 0;
}

