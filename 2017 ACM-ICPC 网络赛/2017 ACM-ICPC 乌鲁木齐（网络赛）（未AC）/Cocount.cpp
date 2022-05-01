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

int main()
{
    cin.sync_with_stdio(false);
    ll t;
    ll N, b;
    cin >> t;
    while(t--)
    {
        cin >> N >> b;
        bool flag = true;
        ll c[10000];
        ll d[10000];
        for(ll i = 1; i <= N; i++)
            cin >> c[i];
        for(ll i = 1; i <= N - 1; i++)
            cin >> d[i];
        ll temp = c[1];
        for(ll i = 2; i <= N; i++)
        {
            if(temp < b)
            {
                flag=false;
                break;
            }
            else
            {
                while(d[i-1]--)
                {
                    temp-=b;
                    if(temp<b)
                    {
                        flag=false;
                        break;
                    }
                }
                temp+=c[i];
            }
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

