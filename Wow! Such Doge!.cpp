/*
Problem:Wow! Such Doge!(HDU 4847,2014西安全国邀请赛)
Author:赵旗
Data:2017-05-17
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
char s[100000];
int main( )
{
    cin.sync_with_stdio(false);
    ll ans=0;
    while(gets(s))
    {
        for(ll i=0; i<strlen(s); i++)
        {
            if(s[i]=='d'||s[i]=='D')
            {
                if(s[i+1]=='o'||s[i+1]=='O')
                {
                    if(s[i+2]=='g'||s[i+2]=='G')
                    {
                        if(s[i+3]=='e'||s[i+3]=='E')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        memset(&s,0,sizeof(s));
    }
    cout<<ans<<endl;
    return 0;
}
