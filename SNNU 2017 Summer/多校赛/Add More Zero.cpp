/*
Problem:Add More Zero
Author:QiZhao
Data:2017-08-07
Description:数学题
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    ll m;
    int flag=0;
    ll ans;
    while(cin>>m)
    {
        flag++;
        ans=static_cast<int>(log10(2)*m);
        cout<<"Case #"<<flag<<": "<<ans<<endl;
    }
    return 0;
}

