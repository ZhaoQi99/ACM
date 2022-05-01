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
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.length(), b.length());
    stack<int> ans;
    int temp, flag = 0;
    for(int i = 0; i < len; i++)
    {
        if (i < a.length() && i < b.length())
        {
            temp = int(a[i] - '0') + int(b[i] - '0') + flag;
            if(s[i] == '0')
            {
                flag = temp / 10;
                temp = temp % 10;
            }
            else
            {
                flag = temp / int(s[i] - '0');
                temp = temp % int(s[i] - '0');
            }
            ans.push(temp);
        }
        else
        {
            if(i >= a.length())
                temp = int(b[i] - '0') + flag;
            else
                temp = int(a[i] - '0') + flag;
            if(s[i] == '0')
            {
                flag = temp / 10;
                temp = temp % 10;
            }
            else
            {
                flag = temp / int(s[i] - '0');
                temp = temp % int(s[i] - '0');
            }
            ans.push(temp);
        }
//        cout << "dasd" << temp << endl;
    }
    bool flag_zero = false;
    while(flag != 0)
    {
        if(flag < int(s[len] - '0'))
        {
            ans.push(flag);
            break;
        }
        else
        {
            temp = flag % int(s[len] - '0');
            flag = flag / int(s[len] - '0');
            ans.push(temp);
        }
        len++;
    }
    while(!ans.empty())
    {
        if(ans.top() != 0)
        {
            flag_zero = true;
            cout << ans.top();
        }
        else if(ans.top() == 0 && flag_zero == true)
            cout << "0";
        ans.pop();
    }
    cout << endl;
    return 0;
}

