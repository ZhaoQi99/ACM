/*
Problem:wmq的共享日历
Author:赵旗
Data:2017-05-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll month,day;
    while(cin>>month>>day){
    ll sum=0;
    for(ll i=1; i<=month-1; i++)
    {
        if(i<=8)
        {
            if(i%2||i==8)
                sum+=31;
            else if(i==2)
                sum+=28;
            else
                sum+=30;
        }
        else
        {
            if(i%2)
                sum+=30;
            else
                sum+=31;
        }
    }
    sum+=day;
    sum=sum%7;
    switch(sum)
    {
    case 1:
        cout<<7;
        break;
    case 2:
        cout<<1;
        break;
    case 3:
        cout<<2;
        break;
    case 4:
        cout<<3;
        break;
    case 5:
        cout<<4;
        break;
    case 6:
        cout<<5;
        break;
    case 0:
        cout<<6;
        break;
    }
    cout<<endl;
    }
    return 0;
}
