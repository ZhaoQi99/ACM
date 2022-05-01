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
    ll value;
    int index;
};
bool operator<(const stu &s1, const stu &s2)
{
    if(s1.value != s2.value)
        return s1.value > s2.value;
    else
        return s1.index < s2.index;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, k;
    struct stu a[2005];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a[i].value = temp;
        a[i].index = i + 1;
    }
    sort(a, a + n);
    ll ans = 0;
    int index[2005];
    for(int i = 0; i < k; i++)
    {
        ans += a[i].value;
        index[i] = a[i].index;
    }
    sort(index, index + k);
    cout << ans << endl;
    ll flag=index[0];
    if(k == 1)
        cout << n << endl;
    else
    {
            cout << index[0] << " ";
            for(int i = 1; i < k - 1; i++)
            {
                ll temp = index[i ] - index[i - 1];
                cout<<temp<<" ";
                flag+=temp;
            }
            cout<<n-flag<<endl;
    }
    return 0;
}

