//未能AC
/*
Problem:Counting-out Rhyme
Author:赵旗
Data:2017-04-25
Description:模拟
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int fun(int orn,ll stu[120],int j);//查找下一个头
int main( )
{
    ll n,k,temp,m;
    ll lead=0;//头的下标编号
    ll ans=0;//要删的人
    cin>>n>>k;
    ll orn=n;//原始人数
    ll step[120],stu[120];
    for(ll i=0;i<k;i++)//读入k个数
        cin>>step[i];
    for(ll i=0;i<n;i++)//学生赋值
        stu[i]=i+1;
    for(ll i=0;i<k;i++)//依次处理k个数
    {
        temp=step[i];
        temp=temp%n;//对当前步数取余
        for(ll j=lead;;j++)
            {
                if(j==orn-1)//重头开始
                    {
                        j=-1;
                        temp--;
                    }
                else
                {
                if(stu[j+1]!=0)//步数减一
                    {
                        temp--;
                        ans=stu[j+1];//记录出局学生编号
                        stu[j+1]=0;
                    }
                }
                if(temp==0)
                    {
                        lead=fun(orn,stu,j);
                        ans=stu[j];
                        stu[j]=0;
                        break;
                    }

            }
        cout<<ans<<" ";
        n--;
    }
    return 0;
}
int fun(int orn,ll stu[120],int j)
{
    ll temp=0;
    while(temp==0)
    {
        for(ll i=j;;i++)
        {
            if(stu[i]!=0)
            {
                temp=1;
                break;
            }
            else
            {
                if(i==orn-1)
                    i=-1;
            }
        }
    }
    return temp;
}
