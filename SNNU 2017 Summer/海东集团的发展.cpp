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
ll a[105];
ll b[105];
int main( )
{
    cin.sync_with_stdio(false);
    ll n;
    ll num1 = 0, num2 = 0;
    while(cin >> n)
    {
        num1 = 0, num2 = 0;
        if(n == 0)
            return 0;
        for(ll i = 0; i < n; i++)
            cin >> a[i];
        for(ll i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for(ll i = 0; i < n; i++)
        {
            if(a[i] > b[i] || a[i] == b[i])
            {
                if(a[i] == b[i])
                {
                    num1++;
                    num2++;
                }
                else
                    num1 += 2;
            }
            else
                num2 += 2;
        }
        cout << num1 << " " << "vs" <<" "<< num2 << endl;
    }
    return 0;
}
