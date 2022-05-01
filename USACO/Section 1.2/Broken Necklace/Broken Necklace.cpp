/*
ID: qizhao11
PROG: beads
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin.sync_with_stdio(false);
    int num,j;
    cin >> num;
    string neck;
    cin >> neck;
    neck=neck+neck;
    int ans = -1;
    int flag;
    bool all=true;
    for(int i=0;i<num;i++)
    {
        if(neck[i]=='w')
            continue;
        else
            all=false;
    }
    if(all)
    {
        cout<<num<<endl;
        return 0;
    }
    for(int i = 0; i < num; i++)
    {
        char symbol;
        int ans_temp = 0;
        j = i;
        while(neck[j] == 'w')
        {
            j++;
            ans_temp++;
            if(j==num-1)
                break;
        }
        symbol = neck[j];
        while(j <= i + num - 1)
        {
            if(neck[j] == symbol || neck[j] == 'w')
                ans_temp++;
            else
                break;
            flag=j;
            j++;
        }
        j = i+num-1;
        while(neck[j] == 'w'&&j!=flag)
        {
            ans_temp++;
            j--;
        }
        symbol = neck[j];
        while(j!=i&&j!=flag)
        {
            if(neck[j] == symbol || neck[j] == 'w')
                ans_temp++;
            else
                break;
            j--;
        }
        if(ans_temp > ans)
            ans = ans_temp;
    }
    cout << ans << endl;
    return 0;
}

