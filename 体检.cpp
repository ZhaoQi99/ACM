#include<iostream>
#include<algorithm>
using namespace std;
int main( )
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>k>>m;//N表示员工的人数，K表示体检的项目数，M表示医生的人数
        if(m>=n)
            cout<<k<<endl;
        else
        {
            int temp;
            temp=n*k;
            if(temp%m==0)
                cout<<temp/m<<endl;
            else cout<<temp/m+1<<endl;
        }
        cout<<endl;
    }
    return 0;
}
