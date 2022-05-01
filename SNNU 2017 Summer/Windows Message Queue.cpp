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

struct Node
{
    string s;
    int val;
    int priority;
    int second;
};

bool operator<(const Node s1, const Node s2)
{
    if(s1.priority == s2.priority)
        return s1.second > s2.second;
    return s1.priority > s2.priority;
}
int main( )
{
    cin.sync_with_stdio(false);
    string s;
    ll k = 0;
    priority_queue<Node>q;
    while(cin >> s)
    {
        if(s == "GET")
        {
            if(q.empty())
                cout << "EMPTY QUEUE!" << endl;
            else
            {
                Node ans = q.top();
                cout << ans.s << " " << ans.val << endl;
                q.pop();
            }
        }
        else
        {
            Node temp;
            cin >> temp.s >> temp.val >> temp.priority;
            temp.second = ++k;
            q.push(temp);
        }
    }
    return 0;
}
