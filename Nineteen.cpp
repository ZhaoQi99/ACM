/*
Problem:Nineteen
Author:赵旗
Data:2017-05-01
Description:字符串统计,CF393A
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    ll ans[4]={0,0,0,0};
    char a[120];
    char temp;
    ll length,b;
    gets(a);
    length=strlen(a);
    for(ll i=0;i<length;i++)
    {
        temp=a[i];
        switch(a[i])
        {
            case 'n':ans[0]++;break;
            case 'i':ans[1]++;break;
            case 't':ans[2]++;break;
            case 'e':ans[3]++;break;
        }
    }
    ans[0]=(ans[0]-1)/2;//1 3  2 5  3 7 4 9
    ans[3]/=3;
    sort(ans,ans+4);
    b=ans[0];
    cout<<b<<endl;
    return 0;
}
