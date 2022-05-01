/*
Problem:
Author:赵旗
Data:2017-07-17
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Node
{
    string name;
    int year;
    int price;
} a[105];

struct Rule1//year
{
    bool operator()(const Node &s1, const Node &s2)
    {
        if(s1.year!=s2.year)
            return s1.year<s2.year;
        else
        {
            if(s1.name!=s2.name)
                return s1.name<s2.name;
            else
                return s1.price<s2.price;
        }
    }
};

struct Rule2//price
{
    bool operator()(const Node &s1, const Node &s2)
    {
        if(s1.price!=s2.price)
            return s1.price<s2.price;
        else
        {
            if(s1.name!=s2.name)
                return s1.name<s2.name;
            else
                return s1.year<s2.year;
        }
    }
};

struct Rule3//name
{
    bool operator()(const Node &s1, const Node &s2)
    {
        if(s1.name!=s2.name)
            return s1.name<s2.name;
        else
        {
            if(s1.year!=s2.year)
                return s1.year<s2.year;
            else
                return s1.price<s2.price;
        }
    }
};

int main( )
{
    cin.sync_with_stdio(false);
    ll t;
    string rule;
    ll flag=0;
    while(cin >> t)
    {
        if(t == 0)
            break;
        if(flag++!=0)
            cout<<endl;
        for(ll i = 0; i < t; i++)
        {
            cin >> a[i].name >> a[i].year >> a[i].price;
        }
        cin >> rule;
        if(rule == "Year")
            sort(a,a+t,Rule1());
        else if(rule == "Price")
            sort(a,a+t,Rule2());
            else
                sort(a,a+t,Rule3());
        for(ll i=0;i<t;i++)
            cout<<a[i].name<<" "<<a[i].year<<" "<<a[i].price<<endl;
    }
    return 0;
}
