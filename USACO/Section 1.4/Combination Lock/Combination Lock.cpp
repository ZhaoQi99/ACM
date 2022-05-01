/*
ID: qizhao11
PROG: combo
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a1,a2,a3;
int b1,b2,b3;

bool close(int a,int b)
{
    //a为密码
    int temp=n+1;
    if(abs(a%temp-b%temp)<=2)
        return true;
    else if(n-b+a<=2)
        return true;
    else if(n-a+b<=2)
        return true;
    else
        return false;
}

bool judge(int i,int j,int k)
{
    if(close(a1,i)&&close(a2,j)&&close(a3,k))
        return true;
    if(close(b1,i)&&close(b2,j)&&close(b3,k))
        return true;
    return false;
}

int main()
{
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin>>n;
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                if(judge(i,j,k))
                {
                    cnt++;
//                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
    cout<<cnt<<endl;
    return 0;
}

