/*
Problem:
Author:QiZhao
Data:
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        vector<int> v;
        forn(i,n)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),greater<int>());
        vector<int>::iterator t1,t2,t3;
        bool flag=false;
        int ans=0;
        for(t1=v.begin();t1!=v.end();t1++)
        {
            if(flag)
                break;
            for(t2=t1,++t2;t2!=v.end();t2++)
            {
                if(flag)
                    break;
                for(t3=t2,t3++;t3!=v.end();t3++)
                {
                    if(*t2+*t3>*t1)
                    {
                        flag=true;
                        ans=(*t1+*t2+*t3);
                        break;
                    }
                }
            }
        }
        if(flag==false)
            cout<<-1<<endl;
            else
                cout<<ans<<endl;
    }
    return 0;
}

