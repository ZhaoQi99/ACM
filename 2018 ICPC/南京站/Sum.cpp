/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef unsigned long long ll;

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
bool flag[20000007];
vector<int> v;
vector<int> vv;
void oula(ll n)
{
    ll cnt = 0;
    int prime[20000];//存素数
    bool vis[20000];//保证不做素数的倍数
    memset(vis, false, sizeof(vis));//初始化
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])//不是目前找到的素数的倍数
        {
            prime[cnt++] = i;//找到素数~
            v.push_back(i * i);
        }
        for(int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = true; //找到的素数的倍数不访问
            if(i % prime[j] == 0)
                break;
        }
    }
}
int res[20000007];
int main()
{
    freopen("in2.txt", "r", stdin);
    //freopen("out2.out", "w", stdout);
    cin.sync_with_stdio(false);
    clock_t start, eend;
    start = clock();
    ll tt;
    cin >> tt;
    oula(4500);
    memset(flag, true, sizeof(flag));
    vector<int>::iterator t = v.begin();
    flag[4] = false;
    for(; t != v.end(); t++)
    {
        for(ll j = 2; j * (*t) < 20000007; j++)
        {
            ll temp = j * (*t);
            flag[temp] = false;
        }
    }
    for(ll i = 1; i < 20000007; i++)
    {
        if(flag[i] == true)
            vv.push_back(i);
    }
    //cout << vv.size() << endl;
    /*
    while(tt--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i = 1; i <= n; i++)
        {
            if(i==1)
            {
                ans++;
                continue;
            }
            if(i==2)
            {
                ans+=2;
                continue;
            }
            t=vv.begin();
            ll ff=sqrt(n);
            for(;t!=vv.end()&&(*t)<=ff;t++)
            {
                ll j=*t;
                if(flag[j] == false)
                    continue;
                if(i%j!=0)
                    continue;
                ll temp = i / j;
                if(temp * j == i && flag[temp] == true)
                {
                    ans++;
                    if(temp != j)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    */
    ll t1, t2;
    for(t1 = 0; t1 < vv.size(); t1++)
    {
        if(vv[t1] * 2 > 20000007)
        {
            res[vv[t1]]++;
            break;
        }
        for(t2 = t1; t2 < vv.size(); t2++)
        {
            ll temp = (vv[t1]) * (vv[t2]);
           // cout<<temp<<endl;
            //getchar();
            if(temp <= 20000007)
            {
                res[temp]++;
                if(vv[t1]!=vv[t2])
                    res[temp]++;
            }
            else
                break;
        }
    }
    while(tt--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i = 1; i <= n; i++)
            ans += res[i];
        cout << ans << endl;
    }
    eend = clock();
    double time=(double)(eend-start);
    cout << time / CLOCKS_PER_SEC << "s" << endl;
    getchar();
    return 0;
}

