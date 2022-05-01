/*
ID: qizhao11
PROG: skidesign
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
//    for(int i=0;i<n;i++)
//        cout<<a[i]<<"|";
    ll cost=0xffffffff;
    for(int i=a[0];i<=a[n-1];i++)
    {
        ll down=i;
        ll up=i+17;
        ll temp=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]>=down&&a[j]<=up)
                continue;
            else
            {
                if(a[j]<down)
                    temp+=(down-a[j])*(down-a[j]);
                else
                    temp+=(a[j]-up)*(a[j]-up);
            }
        }
        if(temp<cost)
            cost=temp;
    }
    cout<<cost<<endl;
    return 0;
}

