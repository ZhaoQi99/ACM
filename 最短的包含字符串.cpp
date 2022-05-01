/*
Problem:×î¶ÌµÄ°üº¬×Ö·û´®(51 nod 1127)
Author:ÕÔÆì
Data:2017-05-06
Description:³ßÈ¡·¨
Copyright  2017 ÕÔÆì. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int flag[26]={0};
ll ans=1e+10;
int main( )
{
    string s;
    getline(cin,s);
    ll right=0,left=0;
    ll cnt=0;
    for(;right<s.length();right++)
    {
        if((flag[s[right]-'A'])==0)
        {
            cnt++;
            flag[s[right]-'A']++;
        }
        while(flag[s[left]-'A']>1)
        {
            flag[s[left]-'A']--;
            left++;
        }
        if(cnt==26)
            ans=min(ans,right-left+1);
    }
    if(ans==1e+10)
        cout<<"No Solution"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}

/*
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
int flag[26]={0};
ll ans=1e+10;
int main( )
{
    string s;
    getline(cin,s);
    ll right=0,left=0;
    ll cnt=0;
    for(;right<s.length();)
    {
        if(flag[s[right]-'A']==0)
        {

        }
            cnt++;
            flag[s[right]-'A']++;
        if(cnt==26)
        {
            ans=min(ans,right-left+1);
            while(cnt==26)
            {
                flag[s[left]-'A']--;
                if(flag[s[left]-'A'==0])
                    cnt--;
                if(cnt==26)
                    ans=min(ans,right-left);
                left++;
            }
        }
        right++;
    }
    if(ans==1e+10)
        cout<<"No Solution"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
*/
