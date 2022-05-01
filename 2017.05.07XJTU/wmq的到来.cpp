/*
Problem:
Author:赵旗
Data:2017-05-07
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;
ll num[4];
using namespace std;

int main( )
{
    ll t;
    cin>>t;
    getchar();
    while(t--)
    {
        string a;
        getline(cin,a);
        memset(num,0,sizeof(num));
        transform(a.begin(),a.end(),a.begin(),::toupper);
        for(ll i=0;i<a.length();i++)
        {
            char temp=a[i];
            switch(temp)
            {
                case 'X':num[0]++;break;
                case 'J':num[1]++;break;
                case 'T':num[2]++;break;
                case 'U':num[3]++;break;
            }
        }
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<" "<<num[3]<<endl;
    }
    return 0;
}
