/*
ID: qizhao11
PROG: ariprog
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct aq
{
    ll a;//首项
    ll q;//公差
};

bool operator <(const aq &s1, const aq &s2)
{
    if(s1.q != s2.q)
        return s1.q < s2.q;
    else
        return s1.a < s2.a;
}

bool have[125005];

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    //找双平方数
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
        {
            ll temp = i * i + j * j;
            a.push_back(temp);
            have[temp] = true;
        }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); //去除重复元素
//    for(vector<ll>::iterator i = a.begin(); i != a.end(); i++)
//        cout << *i <<" ";
    vector<aq> ans;
    bool print = false;
//    cout<<a.size()<<endl;
    for(int k = 0; k < a.size() - n; k++)
    {
        ll a1 = a[k]; //首项
        for(int i = k; i < a.size() - n + 1 ; i++)
        {
            ll q = a[i + 1] - a[k]; //公差
            ll flag = a[i + 1];
            int cnt = 0;
            //找等差数列的n项
            while(true)
            {
                if(flag > 125000||flag+q>125000)
                    break;
                if(have[flag + q])
                {
                    cnt++;
                    flag += q;
                }
                else
                    break;
                if(cnt == n - 2)
                {
                    aq tempans;
                    tempans.a = a1;
                    tempans.q = q;
                    ans.push_back(tempans);
                    print = true;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(print)
    {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].a << " " << ans[i].q << endl;
    }
    else
        cout << "NONE" << endl;
    return 0;
}

