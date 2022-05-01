/*
Problem:
Author:QiZhao
Data:2018-03-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int k;
    cin >> k;
    string a;
    cin >> a;
    int aa[30][30];
    memset(aa, 0, sizeof(aa));
    for(int i = 0; i < a.length() - 1; i++)
    {
        //if(abs(a[i] - a[i + 1]) == 1 || (a[i]=='A'&&a[i+1]=='Z')||abs(a[i] - a[i + 1]) == 0||(a[i]=='Z'&&a[i+1]=='A'))
        //{
           // if(a[i] < a[i + 1])
            aa[a[i] - 'A'][a[i + 1] - 'A']++;
            //else
                //aa[a[i + 1] - 'A'][a[i] - 'A']++;
        //}
    }
    int ans1, ans2;
    int flag = -0xffff;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
        {
            if(aa[i][j] > flag)
            {
                flag = aa[i][j];
                ans1=i;
                ans2=j;
            }
        }
    cout<<(char)(ans1+65)<<(char)(ans2+65)<<endl;
    return 0;
}

