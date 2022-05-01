/*
Problem:Anton and Polyhedrons
Author:赵旗
Data:2017-04-27
Description:字符串匹配
Copyright © 2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main( )
{
    string str1,str2,str3,str4,str5;
    str1="Tetrahedron";
    str2="Cube";
    str3="Octahedron";
    str4="Dodecahedron";
    str5="Icosahedron";
    ll ans=0,n;
    cin>>n;
    while(n--)
    {
        string temp;
        cin>>temp;
        if(str1.find(temp,0)!=-1)
            ans+=4;
        else if(str2.find(temp,0)!=-1)
            ans+=6;
            else if(str3.find(temp,0)!=-1)
                ans+=8;
                else if(str4.find(temp,0)!=-1)
                    ans+=12;
                    else if (str5.find(temp,0)!=-1)
                        ans+=20;
                        else;
    }
    cout<<ans<<endl;
    return 0;
}
