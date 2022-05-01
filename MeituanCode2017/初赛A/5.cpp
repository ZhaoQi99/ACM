//TLE  case:50%
/*
Problem:
Author:赵旗
Data:2017-06-18
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
ll a[50005];
ll b[50005];
ll temp[50005];

bool isCoprime(ll x,ll y)
{
    if(x==1 && y==1)//1和1互质
        return true;
    else if(x<=0 || y<=0 || x==y)//非正整数都不存在互质的说法
        return false;
    else if(x==1 || y==1)//1和任何正整数都互质
        return true;
    else
    {
        int tmp=0;
        //使用求商判断法，如果输入的x<y，第一次循环会交换x和y的位置
        while(true)
        {
            tmp=x%y;
            if(tmp==0)
            {
                break;
            }
            else
            {
                x=y;
                y=tmp;
            }
        }
        if(y==1)          //最大公约数为1,所以互质
            return true;
        else              //最大公约数大于1，所以不互质
            return false;

    }
}
int main( )
{
    cin.sync_with_stdio(false);
    ll n, m;
    ll l, r, k;
    cin >> n >> m;
    for(ll i = 1; i <=n; i++)
        cin >> a[i];
    for(ll i = 0; i < m; i++)
    {
        cin >> l >> r >> k;
        memset(b, 0, sizeof(b));
        memset(temp, 0, sizeof(temp));
        ll flag2 = 0;
        ll* kkk=&temp[0];
        for(ll p = l; p <= r; p++)
        {
            *kkk = a[p];
            kkk++;
        }
        sort(temp, temp + r - l+1);
        ll flag = temp[0];
        ll temp2 = 0;
        for(ll p = 0; p <= r - l; p++)
        {
            if(temp[p] == flag)
                b[temp2]++;
            else
            {
                b[++temp2]++;
                flag = temp[p];
            }
        }
        ll ans = 0;
        for(ll p = 0; p <= temp2; p++)
        {
            if(isCoprime(b[p],k)==true)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
