/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int day,hour,mintue;
        scanf("%d %d:%d",&day,&hour,&mintue);
        if(day==0)
            printf("%d %02d:%02d",day,hour,mintue);
        else
        {
            int temp_hour=(day-1)*24+hour;
            int ans_day=temp_hour/48+1;
            int ans_hour=(temp_hour%48)/2;
            int ans_mintue=(int)(((temp_hour%48)/2.0-ans_hour)*60+mintue/2.0);
        printf("%d %02d:%02d\n",ans_day,ans_hour,ans_mintue);
        }
    }
    return 0;
}

