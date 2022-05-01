/*
ID: qizhao11
TASK: frac1
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu
{
    int a;
    int b;
    stu(int aa,int bb)
    {
        a=aa;
        b=bb;
    }
};

bool operator <(const stu& s1,const stu& s2)
{
    if(s1.b!=s2.b)
        return s1.a*s2.b<s2.a*s1.b;
    else
        return s1.a<s2.a;
}

bool operator ==(const stu& s1,const stu& s2)
{
    if(s1.a*s2.b==s1.b*s2.a)
        return true;
}

set<stu> v;

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            stu temp(i,j);
            v.insert(temp);
        }
    }
    stu temp(0,1);
    v.insert(temp);
    set<stu>::iterator t=v.begin();
    for(;t!=v.end();t++)
    {
        cout<<t->a<<"/"<<t->b<<endl;
    }
    return 0;
}
