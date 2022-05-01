/*
ID: qizhao11
PROG: wormhole
LANG: C++11
*/
///不会写
/*
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu
{
    int x;
    int y;
};

bool operator <(const stu &s1, const stu &s2)
{
    if(s1.x!=s2.x)
        return s1.x<s2.x;
    else
        return s1.y<s2.y;
}

int fun(int m)
{
    //计算组合数C(2/m)
    if(m==2)
        return 1;
    int temp=m;
    int ans=1;
    while(temp--!=m-2)
        ans*=temp;
    ans/=2;
    return ans;
}

int main()
{
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin.sync_with_stdio(false);
    ll n;
    cin >> n;
    stu a[n + 1];
    set<int> cnt;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        cnt.insert(a[i].y);
    }
    sort(a, a + n);
    int ans=0;
    int num=1;
    int flag=a[0].x;
    for(int i=0;i<cnt.size();i++)
    {
        int temp=1;
        while(a[num].x==flag&&num<n)
        {
            temp++;
            num++;
        }
        flag=a[num++].x;
        ans+=fun(temp);
    }
    cout<<ans<<endl;
    return 0;
}
*/
