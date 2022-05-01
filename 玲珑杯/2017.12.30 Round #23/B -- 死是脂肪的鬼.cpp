/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool judge(bool flag[9])
{
    for(int i = 1; i <= 9; i++)
    {
        if(flag[i] == false)
            return false;
    }
    return true;
}

bool judge2(int shudu[9][9],int st,int en)
{
    bool flag[10];
    memset(flag, false, sizeof(flag));
    for(int i = st; i < st+3; i++)
    {
        for(int j = en; j < en+3; j++)
            flag[shudu[i][j]] = true;
    }
    if(judge(flag) == true)
        return true;
    else
        return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
//    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int shudu[9][9];
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cin >> shudu[i][j];
        }
        //judge
        bool ans = true;
        bool flag[10];
        memset(flag, false, sizeof(flag));
        //line
        for(int i = 0; i < 9; i++)
        {
            memset(flag, false, sizeof(flag));
            for(int j = 0; j < 9; j++)
                flag[shudu[i][j]] = true;
            if(judge(flag) == false)
            {
                ans = false;
                break;
            }
        }
        //row
        if(ans == true)
        {
            for(int i = 0; i < 9; i++)
            {
                memset(flag, false, sizeof(flag));
                for(int j = 0; j < 9; j++)
                    flag[shudu[j][i]] = true;
                if(judge(flag) == false)
                {
                    ans = false;
                    break;
                }
            }
        }
        //3*3
        if(ans == true)
        {
            if(judge2(shudu, 0, 0) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 3, 0) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 6, 0) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 0, 3) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 3, 3) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 6, 3) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 0, 6) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 3, 6) == false)
            {
                ans = false;
                break;
            }
            if(judge2(shudu, 6, 6) == false)
            {
                ans = false;
                break;
            }
        }
        //ans
        if(ans == false)
            cout << "No" << endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}

