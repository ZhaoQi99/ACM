#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1000000];
ll ans=1e+10;
int main()
{
    ll n,pos=0;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        if(a[i]-a[i-1]<ans)
        {
            ans=a[i]-a[i-1];
            pos=1;
        }
        else if(a[i]-a[i-1]==ans)
                pos++;
             else;
    }
    cout<<ans<<" "<<pos<<endl;
    return 0;
}
