/*
ID: qizhao11
PROG: friday
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool IsLeapYear(int year)
{
    if(year % 100 == 0)
    {
        if(year % 400==0)
            return true;
        else
            return false;
    }
    else
    {
        if(year % 4 == 0)
            return true;
        else
            return false;
    }
}

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    bool flag;
    cin >> n;
    int a[8];
    int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    memset(a, 0, sizeof(a));
    int sum=13;
    for(int i = 1900; i < 1900 + n; i++)
    {
        flag = IsLeapYear(i);
        if(flag)
            b[2]=29;
        for(int j=1;j<=12;j++)
        {
            int index;
            index=sum%7;
            sum+=b[j];
            a[index]++;//index代表星期几,index=0代表星期日
        }
        b[2]=28;
    }
    //输出
    cout << a[6] << " " << a[0] << " ";
    for(int i = 1; i <= 4; i++)
        cout << a[i] << " ";
    cout << a[5];
    cout << endl;
    return 0;
}

