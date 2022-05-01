#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long a[t];
    long b[t][1000];
    for(int i=0;i<t;i++)
    {
        cin>>a[i];
        for(int j=0;j<a[i];j++)
            cin>>b[i][j];
    }
    int m,temp;
    cin>>m;
    int c[m];
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
        for(int j=0;j<t;j++)
            for(int k=0;k<a[j];k++)
                if(b[j][k]==c[m]){cout<<c[i];temp=1;break;}
    }
    if(temp=1) cout<<"No one is handsome";
    return 0;
}
