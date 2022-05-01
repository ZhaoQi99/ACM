/*
Problem:子串查询
Author:QiZhao
Data:2018-08-04
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

typedef long long ll;
/*
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cout<<"Case #"<<k<<":"<<endl;
        int n,q;
        cin>>n>>q;
        char s[100005];
        cin>>s+1;
        int sum[100005][27];
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(s[i]-'A'==j)
                    sum[i][j]=sum[i-1][j]+1;
                else
                    sum[i][j]=sum[i-1][j];
            }
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ans=0;
            for(int i=0;i<26;i++)
            {
                if(sum[r][i]-sum[l-1][i]>0)
                {
                    ans=sum[r][i]-sum[l-1][i];
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
}
*/
int a[100005];
char s[100005];
struct node
{
    int Min;
    int sum[27];
} num[400005];

int t, n, q, i, L, R;
void buildmin(int left, int right, int cnt)
{
    int mid;
    if(left == right)
    {
        num[cnt].Min = a[left] ;
        int temp = a[left] ;
        num[cnt].sum[temp] = 1;
        return;
    }
    mid = left + (right - left) / 2;
    buildmin(left, mid, cnt * 2);
    buildmin(mid + 1, right, cnt * 2 + 1);
    num[cnt].Min = min(num[2 * cnt].Min, num[2 * cnt + 1].Min);
    for(int i = 0; i < 26; i++)
    {
        num[cnt].sum[i] = num[2 * cnt].sum[i] + num[2 * cnt + 1].sum[i];
    }
    return ;
}

int querymin(int left, int right, int cnt)
{
    int mid;
    if(L <= left && R >= right)
        return num[cnt].Min;
    mid = left + (right - left) / 2;
    int aa = 0xffff, bb = 0xffff;
    if(L <= mid)
        aa = querymin(left, mid, cnt * 2);
    if(R > mid)
        bb = querymin(mid + 1, right, cnt * 2 + 1);
    return min(aa, bb);
}
int querysum(int left, int right, int cnt, int c)
{
    int mid;
    if(L <= left && R >= right)
        return num[cnt].sum[c];
    int ans = 0;
    mid = left + (right - left) / 2;
    if(L <= mid)
        ans += querysum(left, mid, cnt * 2, c);
    if(R > mid)
        ans += querysum(mid + 1, right, cnt * 2 + 1, c);
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin.sync_with_stdio(false);
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        printf("Case #%d:\n", k);
        scanf("%d%d", &n, &q);
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        memset(num, 0, sizeof(num));
        scanf("%s", s+1 );
        for(int i = 1 ; i <= n; i++)
            a[i] = s[i] - 'A';
        buildmin(1, n, 1);
        while(q--)
        {
            scanf("%d%d", &L, &R);
            int res = querymin(1, n, 1);
            int ans = querysum(1, n, 1, res);
            //cout<<res<<":"<<ans<<endl;
            printf("%d\n", ans);
        }
    }
    return 0;
}
