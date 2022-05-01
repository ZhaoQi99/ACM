/*
Problem:名人堂与代金券
Author:QiZhao
Data:2018-04-01
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu
{
    string name;
    int grade;
};
bool cmp(const stu& s1, const stu& s2)
{
    if(s1.grade != s2.grade)
        return s1.grade > s2.grade;
    else
        return s1.name < s2.name;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n, g, k;
    cin >> n >> g >> k;
    vector<stu> v;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        string temp1;
        int temp2;
        cin >> temp1 >> temp2;
        stu temp;
        temp.name = temp1;
        temp.grade = temp2;
        v.push_back(temp);

        if(temp2 >= 60)
        {
            if(temp2 < g)
                ans += 20;
            else
                ans += 50;
        }
    }
    cout << ans << endl;

    int index = 1;
    int number = 1;
    sort(v.begin(), v.end(), cmp);
    vector<stu>::iterator t;
    ll flag = v[0].grade;
    for(t = v.begin(); t != v.end(); t++)
    {
        if(flag != (*t).grade)
        {
            flag = (*t).grade;
            index = number;
        }
        if(index > k)
            break;
        cout << index << " " << (*t).name << " " << (*t).grade << endl;
        number++;
    }
    return 0;
}

