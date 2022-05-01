#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun(ll c)
{
    if(c==1)
        return 0;
    else if(c==2)
        return 1;
    else
        return fun(c-1)+c-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll c;
        cin>>c;
        ll ans=fun(c);
        cout<<ans<<endl;
    }
}
