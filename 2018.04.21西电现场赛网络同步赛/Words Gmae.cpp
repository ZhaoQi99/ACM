/*
Problem:
Author:QiZhao
Data:2018-04-
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
    string a;
    while(cin >> a)
    {
        int zimu[30];
        int zimu_copy[30];
        memset(zimu, 0, sizeof(zimu));
        for(int i = 0; i < a.size(); i++)
        {
            zimu[a[i] - 'a']++;
        }
        ll n;
        cin >> n;
        ll ans = 0;
        while(n--)
        {
            string temp;
            cin >> temp;
            for(int i = 0; i < a.size(); i++)
            {
                zimu_copy[i] = zimu[i];
            }
            bool flag = true;
            for(int i = 0; i < temp.size(); i++)
            {
                if(zimu_copy[temp[i] - 'a'] <= 0)
                {
                    flag = false;
                    break;
                }
                else
                    zimu_copy[temp[i] - 'a']--;
            }
            if(flag == true)
            {
                if(temp.size() > ans)
                    ans = temp.size();
            }
        }
        cout << ans << endl;
    }
    return 0;
}

