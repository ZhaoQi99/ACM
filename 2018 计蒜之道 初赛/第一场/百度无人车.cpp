/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int v[20004];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v + n);
    ll p, s;
    cin >> p >> s;
    ll flag_s = 0;
    ll ans;
    ans=0;
    for(int i = v[n - 1]; i >= 1; i--)
    {
        int flag = i;
        for(int j = n - 1; j >= 0; j--)
        {
            if(v[j] > flag)
            {
                flag_s += p * (v[j] - flag);
                v[j] = flag;
            }
            if(flag_s>s)
                break;
        }
        if(flag_s >= s)
        {
            ans = flag_s==s?flag:flag+1;
            break;
        }
    }
    if(flag_s < s)
    {
        int temp=(s-flag_s)/n*1.0;
        ans=ans-temp;
    }
    if(ans <1)
        ans = 1;
    cout << ans << endl;
    return 0;
}

