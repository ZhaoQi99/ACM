/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>

typedef long long ll;

using namespace std;
ll s[100005];
ll p=1000000;
int num[] =
{
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 0, 7, 7,
	8, 8, 8,
	9, 9, 9
};

int main( )
{
    cin.sync_with_stdio(false);
    memset(s, 0, sizeof(s));
    string a;
    ll n,temp;
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        cin >> a;
        for(ll j = 0; j < a.length(); j++)
        {
            if(a[j] >= '0' && a[j] <= '9')
                s[i] = s[i] * 10 + a[j] - '0';
            else if(a[j] >= 'A' && a[j] <= 'Z')
            {
                temp=num[a[j]-'A'];
                s[i] = s[i] * 10 +temp;
            }
        }
    }
    sort(s, s + n);
    ll count = 1;
    ll flag = 0; //有无重复电话号码
    temp = s[0];
    count = 0;
    ll i = 0;
    while(i != n +1)
    {
        if(temp == s[i])
        {
            if(i!=0)
                flag = 1;
            count++;
            i++;
        }
        else
        {
            p = 1000000;
            if(count != 1)
            {
                for(ll j = 0; j < 3; j++)
                {
                    cout << temp / p;
                    temp = temp % p;
                    p /= 10;
                }
                cout << "-";
                for(ll j = 0; j < 4; j++)
                {
                    cout << temp / p;
                    temp = temp % p;
                    p /= 10;
                }
                cout << " " << count << endl;
            }
            temp = s[i++];
            count=1;
        }

    }
    if(flag == 0)
        cout << "No duplicates." << endl;
    return 0;
}
