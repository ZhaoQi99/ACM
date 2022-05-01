
/*
Problem:
Author:QiZhao
Data:2017-10-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

bool isPrime(ll num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}
	for (ll i = 5; i*i <= num; i += 6)
	{
		if (num % i == 0 || num % (i+2) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    bool flag=true;
    ll n;
    cin>>n;
    while(n--)
    {
        flag=true;
        ll m;
        cin>>m;
        if(isPrime(m)==true||m==4)
            flag=false;
        if(flag)
            cout<<"escape"<<endl;
        else
            cout<<"trapped"<<endl;
    }
    return 0;
}

