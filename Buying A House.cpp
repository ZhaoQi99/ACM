#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=1e+10;

int main()
{
    ll n,m,k;
    ll a[120];
    cin>>n>>m>>k;
    for(ll i=1;i<n+1;i++)//读入n间房子的价格
    {
        cin>>a[i];
    }
    for(ll i=m;i<n+1;i++)//对大于m的村庄
    {
        if(a[i]!=0)
        {
            if(a[i]<=k)
                ans=min(ans,(i-m)*10);
        }
    }
    for(ll i=m;i>=1;i--)//对小于m的村庄
    {
        if(a[i]!=0)
        {
            if(a[i]<=k)
                ans=min(ans,(m-i)*10);
        }
    }
    cout<<ans<<endl;
    return 0;
}
