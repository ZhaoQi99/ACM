/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;
ll dp[100005][2][3];
                //0次缺席，1次缺席
                //连续迟到0次，连续迟到1次 ，连续迟到2次
int main( )
{
    cin.sync_with_stdio(false);
    ll n;
    ll sum = 0;
    cin >> n;
    dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;
    for(ll i = 2; i <=100000; i++)
    {
        dp[i][1][0] = dp[i - 1][1][0] + dp[i - 1][1][1];
        dp[i][1][0] += dp[i - 1][1][2];
        dp[i][1][0] += (dp[i - 1][0][0] + dp[i - 1][0][1]+dp[i-1][0][2]);
        dp[i][1][0] = dp[i][1][0] % mod;
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][1] = dp[i][1][1] % mod;
        dp[i][1][2] = dp[i - 1][1][1];
        dp[i][1][2] = dp[i][1][2] % mod;
        dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1]+dp[i-1][0][2];
        dp[i][0][0] = dp[i][0][0] % mod;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][1] = dp[i][0][1] % mod;
        dp[i][0][2] = dp[i - 1][0][1];
        dp[i][0][2] = dp[i][0][2] % mod;
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            sum += dp[n][i][j];
            sum = sum % mod;
        }
    }
    cout << sum << endl;
    return 0;
}
