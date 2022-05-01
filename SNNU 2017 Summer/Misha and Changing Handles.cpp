/*
Problem:
Author:QiZhao
Data:2017-07-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    map<string,string> d;
    map<string,string>::iterator p;
    ll t;
    cin>>t;
    ll t2=t;
    string a,b;
    while(t--)
    {
        cin>>a;
        cin>>b;
        if(d.find(a)!=d.end())
        {
            d[b]=d[a];
            d.erase(a);
        }
        else
            d.insert(pair<string,string>(b,a));
    }
    cout<<d.size()<<endl;
    for(p=d.begin();p!=d.end();p++)
    {
        cout<<p->second<<" "<<p->first<<endl;
    }
    return 0;
}

