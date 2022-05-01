/*
Problem:
Author:QiZhao
Data:2017-07-17
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<iostream>
#include<string>
#include<map>

using namespace std;

typedef long long ll;

int main()
{
    cin.sync_with_stdio(false);
    map<string, string> d;
    map<string, string>::iterator p;
    string a, b;
    while(cin >> a)
    {
        int len = a.length();
        if(a[len - 1] == 'y' && a[len - 2] == 'a')
            break;
        cin >> b;
        d.insert(pair<string, string>(b, a));
    }
    b = a;
    p = d.find(b);
    if(p == d.end())
        cout << "eh" << endl;
    else
        cout << p->second << endl;
    while(cin >> b)
    {
        p = d.find(b);
        if(p == d.end())
            cout << "eh" << endl;
        else
            cout << p->second << endl;
    }
    return 0;
}

