/*
ID: qizhao11
PROG: milk3
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int a,b,c;
int cnt;
bool vis[21][21][21];
bool ans[21];

void DFS(int aa,int bb,int cc)
{
    if(vis[aa][bb][cc])
        return;
    else
        vis[aa][bb][cc]=true;
    if(aa==0&&!ans[cc])
    {
        ans[cc]=true;
//        cout<<cc<<endl;
        cnt++;
    }
    if(aa>=b-bb)//a->b
        DFS(aa-b+bb,b,cc);
    else
        DFS(0,bb+aa,cc);
    if(bb>=c-cc)//b->c
        DFS(aa,bb-c+cc,c);
    else
        DFS(aa,0,cc+bb);
    if(aa>=c-cc)//a->c
        DFS(aa-c+cc,bb,c);
    else
        DFS(0,bb,cc+aa);
    if(bb>=a-aa)//b->a
        DFS(a,bb-a+aa,cc);
    else
        DFS(aa+bb,0,cc);
    if(cc>=b-bb)//c->b
        DFS(aa,b,cc-b+bb);
    else
        DFS(aa,bb+cc,0);
    if(cc>=a-aa)//c->a
        DFS(a,bb,cc-a+aa);
    else
        DFS(aa+cc,bb,0);
    return;
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    cin.sync_with_stdio(false);
    cin>>a>>b>>c;
    DFS(0,0,c);
    for(int i = 0; i < 21; i++)
    {
        if(ans[i])
        {
            cout << i;
            cnt--;
            if(cnt)
                cout << " ";
        }
    }
    cout<<endl;
    return 0;
}

