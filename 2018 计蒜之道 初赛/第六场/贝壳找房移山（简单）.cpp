///WA
/*
Problem:
Author:QiZhao
Data:2018-05-27
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t;
ll n, k;
ll a[15];

int fun()
{
    int cnt = 0;
    int flag = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        if(a[i] > flag && (a[i + 1] == a[i] || a[i + 1] < a[i]))
        {
            if(a[i + 1] < a[i])
            {
                flag = a[i + 1];
                i++;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        int ans = 0;
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        a[n + 1] = 0;
        //sort(a + 1, a + n + 1);
        while(true)
        {
            int cnt = fun();
            //cout<<cnt<<endl;
            if(cnt <= k)
                break;
            int MAX = -0xffff;
            int index;
            for(int i = 1; i <= n; i++)//找当前最高的
            {
                if(a[i] > MAX)
                {
                    MAX = a[i];
                    index = i;
                }
            }
            int index2;
            for(int i = index; i <= n; i++)
            {
                if(a[i] != MAX)
                {
                    index2 = i - 1;
                    break;
                }
            }
            int f = min(a[index - 1], a[index2 + 1]);
            while(a[index] != f)
            {
                ans++;
                for(int i = index; i <= index2; i++)
                {
                    a[i]--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

