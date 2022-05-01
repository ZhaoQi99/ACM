/*
ID: qizhao11
PROG: milk
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
struct stu
{
    int price;
    ll unit;
};

bool operator <(const stu &s1, const stu &s2)
{
    return s1.price<s2.price;
}

int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    stu a[5003];
    for(ll i = 0; i < m; i++)
        cin >> a[i].price >> a[i].unit;
    sort(a, a + m);
    ll ans=0;
    int index=0;
    while(n!=0)
    {
        ll temp=a[index].unit;
        if(temp>n)
            temp=n;
        n-=temp;
        ans+=a[index].price*temp;
        index++;
    }
    cout<<ans<<endl;
    return 0;
}

