/*
Problem:
Author:赵旗
Data:2017-05-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

int main( )
{
    ll t;
    int temp;
    cin>>t;
    while(t--)
    {
        char a[100005];
        memset(a,0,sizeof(a));
        ll b;
        cin>>a;
        cin>>b;
        char c;
        c=a[strlen(a)-1];
        temp=(int)c-48;
        if(b==0)
        {
            cout<<1<<endl;
        }
        else
        {
            if(temp==5||temp==6||temp==0||temp==1)
                temp=temp;
            else
            {
                if(temp==4||temp==9)
                {
                    if(b%2==1)
                        temp=temp;
                    else
                    {
                        switch(temp)
                        {
                        case 4:
                            temp=6;
                            break;
                        case 9:
                            temp=1;
                            break;
                        }
                    }
                }
                else if(temp==2)
                {
                    switch(b%4)
                    {
                    case 1:
                        temp=2;
                        break;
                    case 2:
                        temp=4;
                        break;
                    case 3:
                        temp=8;
                        break;
                    case 0:
                        temp=6;
                        break;
                    }
                }
                else if(temp==3)
                {
                    switch(b%4)
                    {
                    case 1:
                        temp=3;
                        break;
                    case 2:
                        temp=9;
                        break;
                    case 3:
                        temp=7;
                        break;
                    case 0:
                        temp=1;
                        break;
                    }
                }
                else if(temp==8)
                {
                    switch(b%4)
                    {
                    case 1:
                        temp=8;
                        break;
                    case 2:
                        temp=4;
                        break;
                    case 3:
                        temp=2;
                        break;
                    case 0:
                        temp=6;
                        break;
                    }
                }
                else if(temp==7)
                {
                    switch(b%4)
                    {
                    case 1:
                        temp=7;
                        break;
                    case 2:
                        temp=9;
                        break;
                    case 3:
                        temp=3;
                        break;
                    case 0:
                        temp=1;
                        break;
                    }
                }
            }
            cout<<temp<<endl;
        }
    }
    return 0;
}
