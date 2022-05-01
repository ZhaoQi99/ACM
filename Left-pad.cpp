#include<iostream>
#include<cstdMonokai
#include<cstring>
using namespace std;
int main()
{
    long long n;
    char a;
    char b[100000];
    cin>>n>>a;
    getchar();
    gets(b);
    long i=strlen(b);
    if(n<i)cout<<b[i-4]<<b[i-3]<<b[i-2]<<b[i-1];
    else
    {
        for(long j=0;j<n-i;j++)
            cout<<a;
        cout<<b;
    }
    cout<<endl;
    return 0;
}