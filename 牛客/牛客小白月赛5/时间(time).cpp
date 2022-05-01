/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu
{
    int hour;
    int minute;
};

bool operator <(const stu &s1, const stu& s2)
{
    if(s1.hour == s2.hour)
        return s1.minute < s2.minute;
    else
        return s1.hour < s2.hour;
}

bool operator ==(const stu &s1, const stu& s2)
{
    if(s1.hour == s2.hour && s1.minute == s2.minute)
        return true;
    else
        return false;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    int a, b;
    scanf("%d:%d", &a, &b);
    stu in;
    in.hour = a;
    in.minute = b;
    vector<stu> result;
    for(int i = 0; i < 24; i++)
    {
        stu temp;
        temp.hour = i;
        temp.minute = i % 10 * 10 + i / 10;
        if(temp.minute < 60)
            result.push_back(temp);
    }
    stu ans1, ans2;
    sort(result.begin(), result.end());
    vector<stu>::iterator t= upper_bound(result.begin(), result.end(), in);
    if(t==result.end())
        ans1=result[0];
    else
        ans1=*t;
    int index = lower_bound(result.begin(), result.end(), in) - result.begin();
    index--;
    while(1)
    {
        if(index == -1)
            index = result.size() - 1;
        if(result[index] < in)
        {
            ans2 = result[index];
            break;
        }
        else
            index--;
    }
    printf("%d:%d\n", ans2.hour, ans2.minute);
    printf("%d:%d\n", ans1.hour, ans1.minute);
    return 0;
}

