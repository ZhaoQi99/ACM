/*
Problem:名人堂与代金券
Author:QiZhao
Data:2018-04-01
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cmp (const pair<string,int>& a,const pair<string,int>& b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first<b.first;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n,g,k;
    cin>>n>>g>>k;
    map<string,int> m;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        string temp1;
        int temp2;
        cin>>temp1>>temp2;
        m.insert(pair<string,int>(temp1,temp2));
        if(temp2>=60)
        {
            if(temp2<g)
                ans+=20;
            else
                ans+=50;
        }
    }
    cout<<ans<<endl;

    vector<pair<string,int>> mm(m.begin(),m.end());//map转存至vector
    sort(mm.begin(),mm.end(),cmp);

    int index=1;
    int number=1;
    vector<pair<string,int>>::iterator t=mm.begin();
    ll flag=(*t).second;
    for(t=mm.begin();t!=mm.end();t++)
    {
        if(flag!=(*t).second)
        {
            flag=(*t).second;
            index=number;
        }
        if(index>k)
            break;
        cout<<index<<" "<<(*t).first<<" "<<(*t).second<<endl;
        number++;
    }
    return 0;
}

