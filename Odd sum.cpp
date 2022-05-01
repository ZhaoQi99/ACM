/*
Problem:Odd sum
Author:赵旗
Data:2017-04-24
Description:sort,所有正数相加。若为奇数，输出答案；若为偶数，减去绝对值最小的奇数。
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll a[1000010];
int main( )
{
    ll t,sum=0,temp=0,temp1=-1e6,temp2=1e6;
    cin>>t;
    for(ll i=0;i<t;i++)
        cin>>a[i];
    for(ll i=0;i<t;i++)
    {
        if(a[i]>0)//最小正奇数
        {
            if(a[i]%2)
                temp2=min(temp2,a[i]);
            sum+=a[i];
        }
        if(a[i]<0)//最大负奇数
        {
            if(a[i]%2)
                temp1=max(temp1,a[i]);
        }
    }
    if(sum%2)
        cout<<sum<<endl;
    else
    {
        sum=max(sum+temp1,sum-temp2);
        cout<<sum<<endl;
    }
    return 0;
}
