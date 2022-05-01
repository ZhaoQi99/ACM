/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<iostream>
#include<algorithm>
#include<string.h>
typedef long long ll;

using namespace std;
int a[1010];
int main( )
{
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=0;i<10;i++)
            cin>>a[i];
        sort(a,a+10,greater<int>());
        cout<<n<<" "<<a[2]<<endl;
    }
    //system("pause");
    return 0;
}
