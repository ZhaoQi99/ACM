/*
ID: qizhao11
PROG: gift1
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
struct person
{
    string name;
    int money = 0;
};

int Find(person a[], string m)
{
    //查找下标
    int k;
    for(int j = 0; ; j++)
    {
        k = j;
        if(m.compare(a[j].name) == 0)
            return k;
    }
}
int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    struct person a[t];
    for(int i = 0; i < t; i++)
    {
        string temp;
        cin>>temp;
        a[i].name = temp;
    }
    for(int i = 0; i < t; i++)
    {
        string temp;
        cin>>temp;
        int k = Find(a, temp);
        ll m, n;
        cin >> m >> n;
        int money;//要分出去的钱数
        if(n!=0)
            money = (int)m / n;
        a[k].money -= money * n;
        for(int j = 0; j < n; j++)
        {
            cin>>temp;
            int index = Find(a, temp);
            a[index].money += money;
        }
    }
    //输出
    for(int i = 0; i < t; i++)
    {
        cout << a[i].name << " " << a[i].money << endl;
    }
    return 0;
}

