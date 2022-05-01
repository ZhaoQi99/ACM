/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
struct m
{
    int p;
    int v;
};
struct rule
{
    bool operator()(const m &s1,const m &s2)
    {
        if(s1.p>s2.p||s1.p==s2.p)
            return true;
        else
            return false;
    }
};
m thing[105];
int main( )
{
    cin.sync_with_stdio(false);
    int v,n;
    int sum=0;
    while(cin>>v)
    {
        sum=0;
        if(v==0)
            return 0;
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>thing[i].p>>thing[i].v;
        sort(thing,thing+sizeof(thing[0])/sizeof(m)*n,rule());
        for(ll i=0;i<n;i++)
        {
            if(v==0)
                break;
            if(v>=thing[i].v)
            {
                sum+=thing[i].p*thing[i].v;;
                v-=thing[i].v;
            }
            else
            {
                sum+=v*thing[i].p;
                v=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
