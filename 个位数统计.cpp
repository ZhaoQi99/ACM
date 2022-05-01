#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[1000];
    int b[10]={0};
    cin>>a;
    for(int i=0;i<strlen(a);i++)
    {
        int temp=a[i]-48;
        b[temp]++;
    }
    for(int i=0;i<10;i++)
    {
        if(b[i]!=0)
            cout<<i<<":"<<b[i]<<endl;
    }
    return 0;
}
