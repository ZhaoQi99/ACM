WA
/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    cin.sync_with_stdio(false);
    string s;
    ll ans[7];
    for(ll i=0;i<7;i++)
        ans[i]=0;
    while(cin >> s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(ll i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case 'i':ans[0]++;
                case 'l':ans[1]++;
                case 'o':ans[2]++;
                case 'v':ans[3]++;
                case 'e':ans[4]++;
                case 'c':ans[5]++;
                case 's':ans[6]++;
            }
        }
        ans[4]/=2;
        sort(ans,ans+7);
        cout<<ans[0]<<endl;
    }
    return 0;
}
