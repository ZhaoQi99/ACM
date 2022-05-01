#include<iostream>
#include<cmath>
using namespace std;
struct stu
{
    int r;
    int n;
    int x;
};
int fun(int a,int b,int c)
{
    int sum=0;
    for(int j=1;j<=a;j++)
        if(abs(j-c)<=b) sum++;
    return sum;
}
int main()
{
    int t;
    cin>>t;
    struct stu a[t];
    for(int i=0;i<t;i++)
    {
        cin>>a[i].r>>a[i].n>>a[i].x;
        cout<< fun(a[i].r,a[i].n,a[i].x)<<endl;
    }
    return 0;
}
