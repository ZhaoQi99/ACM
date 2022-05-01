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

int main( )
{
    cin.sync_with_stdio(false);
    string a;
    ll z, o, j;
    while(cin >> a)
    {
        if(a[0] == 'E')
            return 0;
        z = 0;
        o = 0;
        j = 0;
        for(ll i = 0; i < a.length(); i++)
        {
            switch(a[i])
            {
                case 'Z':z++;break;
                case 'O':o++;break;
                case 'J':j++;break;
            }
        }
        while(z!=0||j!=0||o!=0)
        {
            if(z!=0)
            {
                z--;
                cout<<"Z";
            }
            if(o!=0)
            {
                o--;
                cout<<"O";
            }
            if(j!=0)
            {
                j--;
                cout<<"J";
            }
        }
        cout<<endl;
    }
    return 0;
}
