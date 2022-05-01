/*
陕西师范大学第五届程序设计大赛
1148: 最大值
*/
#include<iostream>
#include<algorithm>
using namespace std;
int z(int x,int y);
int main()
{
    int t;
    cin>>t;
    long long temp;
    while(t--)
    {
        int n;
        long long max=0;
        cin>>n;
        int aa[n];
        for(int i=0;i<n;i++)
            cin>>aa[i];
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
            {
                temp=z(aa[i],aa[j]);
                if(temp>max)
                    max=temp;
                else;
            }
        cout<<max<<endl;
    }
    return 0;
}
int z(int x,int y)
{
    if(x<0&&y>0||x>0&&y<0)
        return 0;
    if(x>0&&y>0)return x*y;
    long long max;
    long long a,b,c,d,e=0,f=0;
    long long result[6];
    result[0]=a=x+y;
    result[1]=b=x-y;
    result[2]=c=y-x;
    result[3]=d=x*y;
    if(y!=0)result[4]=e=x/y;
    else result[4]=0;
    if(x!=0)result[5]=f=y/x;
    else result[5]=0;
    sort(result,result+6);
    max=result[5];
    return max;
}
