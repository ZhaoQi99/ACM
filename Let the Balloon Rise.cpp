/*
Problem:Let the Balloon Rise
Author:赵旗
Data:2017-05-03
Description:模拟，字符串匹配；HDU1004
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

struct str//定义结构体
{
    long num;
    char color[1000];
};

struct Rule//按照num的大小排序
{
    bool operator()(const str &a,const str &b)
    {
        return a.num>b.num;
    }
};

int main()
{
    long t,temp=0,flag=0;
    while(1)
    {
        cin>>t;
        str b[1010];
        if(t==0)
            break;
        for(int i=0;i<t;i++)
        {
            cin>>b[i].color;
            b[i].num=1;
        }
        for(int i=0;i<t;i++)
            for(int j=1;j<t;j++)
            {
                if(strcmp(b[j].color,b[i].color)==0)
                    b[i].num+=1;
            }
        sort(b,b+t,Rule());
        cout<<b[0].color<<endl;
    }
    return 0;
}
