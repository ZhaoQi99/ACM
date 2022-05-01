/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    while(cin>>n)
    {
        n++;
        if(n==1)
            cout<<0<<endl;
        else
        {
            if(n%2==0)
            {
                cout<<n/2<<endl;
            }
            else
            {
                cout<<n<<endl;
            }
        }
    }
    return 0;
}

