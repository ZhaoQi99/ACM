#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct stu
{
    int N;
    int C0;
    int C1;
    int N0;
    int N1;
};
int main()//超时
{
    int t,sum;
    cin>>t;
    struct stu a[t];
    for(int i=0;i<t;i++)
    {
        sum=0;
        cin>>a[i].N>>a[i].C0>>a[i].C1>>a[i].N0>>a[i].N1;
        getchar();
        char N[a[i].N];
        gets(N);
        for(int j=0;j<a[i].N;j++)
        {
            int temp=0;
            if(N[j]=='?'){
            if(a[i].C0<a[i].C1)
            {
                for(int k=j-a[i].N0+1;k<=j+a[i].N0-1;k++)
                {
                    if(N[k]=='0')temp++;
                    if(temp==a[i].N0-1) {sum+=a[i].C1;N[j]='1';break;}
                }
                if(temp!=a[i].N0-1) {sum+=a[i].C0;N[j]='0';}
            }
            else if(a[i].C0>a[i].C1)
            {
                for(int k=j-a[i].N1+1;k<=j+a[i].N1-1;k++)
                {
                    if(N[k]=='1')temp++;
                    if(temp==a[i].N1-1) {sum+=a[i].C0;N[j]='0';break;}
                }
                if(temp!=a[i].N1-1) {sum+=a[i].C1;N[j]='1';}
            }
            else sum+=a[i].C0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

