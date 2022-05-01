/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lowbit(ll x)
{
    return x & (-x);
}
ll fun(ll l, ll r)
{
    if(l >= r)
        return 0;
    if(r - lowbit(r) >= l)
        return fun(l, r - lowbit(r)) + 1;
    return fun(l, r - 1) + 1;
}

string  bin(ll x)
{
    string s;
    ll i;
    while(x != 0)
    {
        i = x % 2;
        s += i + '0';
        x = x / 2;
    }
    string ss(s.rbegin(), s.rend());
    return ss;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    int len = s.length();
    int pos = 0;
    //特判
    if(s == "1")
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i < len; i++)
    {
        if(s[i] == '1')
        {
            pos = i;
            break;
        }
    }
    if(pos != 0)
    {
        for(int i = pos + 1; i < len; i++)
        {
            if(s[i]=='0')
            {
                s[pos]='0';
                for(int j=pos+1;j<len;j++)
                    s[j]='1';
                break;
            }
        }
    }
    int num=0;
    int num2=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
            num++;
        else
            num2++;
    }
    ll ans=0;
    if(num==0)
    {
        ans=len+len*(len-1)/2-1;
    }
    else
    {
        len--;
        ans=len+len*(len-1)/2+num2-1;
    }
    cout<<ans<<endl;
    return 0;
}

/*
ll a = 0;
for(int i = 0; i < 200; i++)
{
    ll MAX = -0xffff;
    for(int l = 0; l < i; l ++)
    {
        for(int r = 0; r < i; r++)
        {
            ll temp = fun(l, r);
            if(temp > MAX)
                MAX = temp;
        }
    }
    cout << i << ":" << MAX <<"||" <<bin(i)<<endl;
}
*/
