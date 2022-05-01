/*
ID: qizhao11
PROG: namenum
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("dict.txt", "r", stdin);
    freopen("namenum.out", "w", stdout);
    char dict [5005][30];
    int key[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,0};
    int count=0;
    while(scanf("%s",dict[count])!=EOF)
        count++;
    freopen("namenum.in", "r", stdin);
    char num[30];
    scanf("%s",num);
    int len=strlen(num);
    bool flag=false,flag2=false;
    for(int i=0;i<count;i++)
    {
        flag=false;
        int temp_len=strlen(dict[i]);
        if(temp_len!=len)
            continue;
        for(int j=0;j<len;j++)
        {
            int temp=dict[i][j]-'A';
            if(key[temp]!=static_cast<int>(num[j]-'0'))
                break;
            if(j==len-1)
                flag=true;
        }
        if(flag)
        {
            flag2=true;
            cout<<dict[i]<<endl;
        }
    }
    if(!flag2)
        cout<<"NONE"<<endl;
    return 0;
}

