/*
ID: qizhao11
PROG: barn1
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    cin.sync_with_stdio(false);
    int m, s, c;
    cin >> m >> s >> c;
    int temp[300];
    for(int i = 0; i < c; i++)
        cin >> temp[i];
    sort(temp, temp + c);
    if(m >= c)
        cout << c << endl;
    else
    {
        int dis[c];
        for(int i=0;i<c-1;i++)
            dis[i]=temp[i+1]-temp[i];
        sort(dis,dis+c-1,greater<int>());
        int ans = temp[c-1]-temp[0]+1;
        for(int i=0;i<m-1;i++)
            ans-=dis[i]-1;
        cout<<ans<<endl;
    }
    return 0;
}

