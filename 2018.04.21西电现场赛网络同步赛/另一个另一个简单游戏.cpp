/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int sum = 0;
        int tmp;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            sum += tmp;
        }
        cout << floor(sum / n) << endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        stack<int> s;
        for(ll i=0;i<n;i++)
        {
            int x;
            cin>>x;
            s.push(x);
        }
        while(s.size()!=1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int c=static_cast<int>((a+b)/2.0);
            s.push(c);
        }
        cout<<static_cast<int>( s.top())<<endl;
    }
    return 0;
}
*/
