/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
/*
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        char flag = a[i];
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] != flag)
            {
                if(!(b[i] == '1' && b[j] == '1'))
                {
                    ans++;
                    //cout<<i+1<<":"<<j+1<<endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    ll ans = 0;
    ll aa[4];
    memset(aa,0,sizeof(aa));
    for(int i = 0; i < n; i++)
    {
        if(a[i]=='0'&&b[i]=='0')
            aa[0]++;
        else if(a[i]=='1'&&b[i]=='1')
            aa[1]++;
        else if(a[i]=='1'&&b[i]=='0')
            aa[2]++;
        else
            aa[3]++;
    }
    ans=aa[0]*(aa[1]+aa[2])+aa[2]*aa[3];
    cout<<ans<<endl;
    return 0;
}
