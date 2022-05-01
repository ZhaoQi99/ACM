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

int team[1000006];

int main( )
{
    cin.sync_with_stdio(false);
    int t,temp1,temp2;
    int flag=0;
    string s;
    //freopen("in.txt","r",stdin);
    while(cin>>t)
    {
        queue<int>a;
        queue<int>b[1005];
        memset(team,0,sizeof(team));
        if(t==0)
            break;
        flag++;
        for(ll i=1;i<=t;i++)
        {
            cin>>temp1;
            for(ll j=0;j<temp1;j++)
            {
                cin>>temp2;
                team[temp2]=i;
            }
        }
        cout<<"Scenario #"<<flag<<endl;
        while(cin>>s)
        {
            if(s=="STOP")
            {
                break;
            }
            else if(s=="ENQUEUE")
            {
                cin>>temp1;
                if(b[team[temp1]].empty())
                {
                    a.push(team[temp1]);
                    b[team[temp1]].push(temp1);
                }
                else
                    b[team[temp1]].push(temp1);
            }
            else
            {
                temp2=a.front();
                cout<<b[temp2].front()<<endl;
                b[temp2].pop();
                if(b[temp2].empty())
                    a.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
