/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
struct stu
{
    int a;
    int b;
    int c;
    int d;
    int id;
};
bool operator <(const stu&s1,const stu&s2)
{
    int sum1=s1.a+s1.b+s1.c+s1.d;
    int sum2=s2.a+s2.b+s2.c+s2.d;
    if(sum1==sum2)
        return s1.id>s2.id;
    else
        return sum1<sum2;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    vector<stu> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        stu temp;
        temp.id=i+1;
        cin>>temp.a>>temp.b>>temp.c>>temp.d;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    vector<stu>::reverse_iterator t;
    int ans=1;
    for(t=v.rbegin();t!=v.rend();t++)
    {
        if(t->id==1)
        {
            break;
        }
        else
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

