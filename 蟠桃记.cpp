/*
Problem:HDU2013
Author:赵旗
Data：2017-4-22
Description:递归
*/
#include<iostream>
using namespace std;
int fun(int t);
int main()
{
    int t,sum;
    while(cin>>t)
    {
        sum=fun(t);
        cout<<sum<<endl;
    }
    return 0;
}
int fun(int t)
{
    int sum=1;
    for(int i=0;i<t-1;i++)
        sum=(sum+1)*2;
    return sum;
}
