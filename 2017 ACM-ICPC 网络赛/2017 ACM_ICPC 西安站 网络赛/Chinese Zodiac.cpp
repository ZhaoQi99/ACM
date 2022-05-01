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
//rat, ox, tiger, rabbit, dragon, snake, horse, sheep, monkey, rooster, dog and pig.
int main()
{
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        ll c=0,d=0;
        string temp[12]={"rat","ox","tiger","rabbit","dragon","snake","horse","sheep","monkey","rooster","dog","pig"};
        for(ll i=0;i<12;i++)
        {
            if(temp[i]==a)
            {
                c=i+1;
                break;
            }
        }
        for(ll i=0;i<12;i++)
        {
            if(temp[i]==b)
            {
                d=i+1;
                break;
            }
        }
        ll temp1=d-c;
        if(temp1<0)
            temp1+=12;
        if(c==d)
            cout<<12<<endl;
        else
            cout<<temp1<<endl;
    }
    return 0;
}

