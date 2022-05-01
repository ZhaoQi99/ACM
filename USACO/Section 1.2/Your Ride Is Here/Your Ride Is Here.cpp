/*
ID: qizhao11
PROG: ride
LANG: C++
*/
#include<bits/stdc++.h>
#include <fstream>
typedef long long ll;

using namespace std;

int main( )
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin>>a;
    fin>>b;
    ll temp1=1,temp2=1;
    for(ll i=0; i<a.length(); i++)
        temp1*=(a[i]-'A'+1);
    for(ll i=0; i<b.length(); i++)
        temp2*=(b[i]-'A'+1);
    temp1=temp1%47;
    temp2=temp2%47;
    if(temp1==temp2)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}
