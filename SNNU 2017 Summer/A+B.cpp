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
char a[30];
char b[30];
ll num1=0, num2=0;
int main( )
{
    cin.sync_with_stdio(false);
    while(scanf("%s%s", a, b) != EOF)
    {
        num1=0, num2=0;
        ll len1=strlen(a);
        ll len2=strlen(b);
        ll temp;
        for(ll i = 0; i < len1; i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
            {
                temp=static_cast<ll>(a[i] - '0');
                num1 = num1*10 + temp;
            }
        }
        if(a[0] == '-')
            num1 = -num1;
        for(ll i = 0; i < len2; i++)
        {
            if(b[i] >= '0' && b[i] <= '9')
            {
                num2 = num2 * 10 + static_cast<ll>(b[i] - '0');
            }
        }
        if(b[0] == '-')
            num2 = -num2;
        cout << num1 + num2 << endl;
    }
    return 0;
}
