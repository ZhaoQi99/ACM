/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
char a[1005];
int main( )
{
    cin.sync_with_stdio(false);
    ll flag = 0,temp=0;
    ll num1 = 0, num2 = 0, num3 = 0;
    bool f = true;
    while(scanf("%s", a) != EOF)
    {
        num1 = 0, num2 = 0, num3 = 0;
        flag = 0;
        temp=0;
        f = true;
        ll len = strlen(a);
        for(ll i=0;i<len;i++)
        {
            if(a[i]=='z')
            {
                flag=i;
                break;
            }
            else if(a[i]=='o')
                num1++;
        }
        for(ll i=flag+1;i<len;i++)
        {
            if(a[i]=='j')
            {
                flag=i;
                break;
            }
            else if(a[i]=='o')
                num2++;
        }
        for(ll i=flag+1;i<len;i++)
        {
            if(a[i]=='o')
                num3++;
        }
        for(ll i=0;i<len;i++)
        {
            if(a[i]=='z'||a[i]=='j')
                temp++;
        }
        if(temp!=2)//z,j只能出现一次
            f=false;
        if(f == false||num2==0)
            cout << "Wrong Answer" << endl;
        else
        {
            if(num1 * num2 == num3)
                cout << "Accepted" << endl;
            else
                cout << "Wrong Answer" << endl;
        }
        memset(a,0,sizeof(a));
    }
    return 0;
}
