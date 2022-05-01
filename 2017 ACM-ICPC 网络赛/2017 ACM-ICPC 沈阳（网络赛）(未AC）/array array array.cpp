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


ll B[1000006]; //在动态规划中使用的数组,用于记录中间结果,其含义三言两语说不清,请参见博文的解释
int len; //用于标示B数组中的元素个数

int LIS(ll *array, int n); //计算最长递增子序列的长度,计算B数组的元素,array[]循环完一遍后,B的长度len即为所求
int BiSearch(ll *b, int len, ll w); //做了修改的二分搜索算法


int LIS(ll *array, int n)
{
    len = 1;
    B[0] = array[0];
    int i, pos = 0;

    for(i=1; i<n; ++i)
    {
        if(array[i] > B[len-1]) //如果大于B中最大的元素，则直接插入到B数组末尾
        {
            B[len] = array[i];
            ++len;
        }
        else
        {
            pos = BiSearch(B, len, array[i]); //二分查找需要插入的位置
            B[pos] = array[i];
        }
    }

    return len;
}

//修改的二分查找算法，返回数组元素需要插入的位置。
int BiSearch(ll *b, int len, ll w)
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right-left)/2;
        if (b[mid] > w)
            right = mid - 1;
        else if (b[mid] < w)
            left = mid + 1;
        else    //找到了该元素，则直接返回
            return mid;
    }
    return left;//数组b中不存在该元素，则返回该元素应该插入的位置
}

int main()
{
    cin.sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,k;
        cin>>a>>k;
        ll num[a+10];
        for(ll i=0;i<a;i++)
            cin>>num[i];
        ll result[a+10];
        ll ans1=0,ans2=0;
        ans1=LIS(num,a);
        //ans2=Fun(num,result,a);
        ll temp;
        temp=a-max(ans1,ans2);
        if(temp<=k)
            cout<<"A is a magic array."<<endl;
        else
            cout<<"A is not a magic array."<<endl;
    }
    return 0;
}

