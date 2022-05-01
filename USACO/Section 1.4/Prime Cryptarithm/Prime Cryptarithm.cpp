/*
ID: qizhao11
PROG: crypt1
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int num[20];

int have[20];

bool in(int x)
{
    while(x!=0)
    {
        int t=x%10;
        x/=10;
        if(!have[t])
            return false;
    }
    return true;
}
bool judge(int a,int b,int c,int d,int e)
{
    int x=a*100+b*10+c;
    int y=d*10+e;
    if(x<100||x>999)
        return false;
    if(y<10||y>99)
        return false;
    int temp1=x*e;
    int temp2=x*d;
    int temp3=temp1+temp2*10;
    if(temp1<100||temp1>999)
        return false;
    if(temp2<100||temp2>999)
        return false;
    return in(temp1)&&in(temp2)&&in(temp3);
}

int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    cin.sync_with_stdio(false);
    int n;
    cin>>n;
    memset(have,0,sizeof(have));
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        have[num[i]]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int l=0;l<n;l++)
                    for(int m=0;m<n;m++)
                    {
                        if(judge(num[i],num[j],num[k],num[l],num[m]))
                            cnt++;
                    }
    cout<<cnt<<endl;
    return 0;
}

