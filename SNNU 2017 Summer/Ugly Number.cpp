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

ll ugly[1600];
ll min(ll a,ll b,ll c)
{
    ll temp[3];
    temp[0]=a;
    temp[1]=b;
    temp[2]=c;
    sort(temp,temp+3);
    return temp[0];
}
int  main()
{
    cin.sync_with_stdio(false);
    ll index1=0;
    ll index2=0;
    ll index3=0;
    ll count=1;
    ll temp;
    ugly[0]=1;
    while(count<1600)
    {
        temp=min(ugly[index1]*2,ugly[index2]*3,ugly[index3]*5);
        if(temp==ugly[index1]*2)
            index1++;
        if(temp==ugly[index2]*3)
            index2++;
        if(temp==ugly[index3]*5)
            index3++;
        ugly[count]=temp;
        count++;
    }
    cout<<"The 1500'th ugly number is "<<ugly[1499]<<"."<<endl;//859963392
    return 0;
}

