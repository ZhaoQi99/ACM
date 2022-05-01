#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
      return a>b;
}
int main()
{
    char a[20];
    int arr[10],index[11],flag(0),temp(0);
    gets(a);
    for(int i=0;a[i]!='\0';i++)
    {
        flag=0;
        for(int j=0;j<i;j++)
            if(a[i]==a[j])flag=1;
        if(flag==0)arr[temp++]=a[i]-'0';
    }
    sort(arr,arr+temp,cmp);
    for(int i=0;a[i]!='\0';i++)
    {
        for(int j=0;j<temp;j++)
        {
            if(arr[j]==a[i]-'0'){index[i]=j;break;}
        }
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<temp-1;i++)cout<<arr[i]<<",";
    cout<<arr[temp-1]<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i=0;i<10;i++)cout<<index[i]<<",";
    cout<<index[10]<<"};"<<endl;
    return 0;
}
