/*
ID: qizhao11
PROG: transform
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
char Map[100][100];
char Map2[100][100];
int n;

void Print(char temp[100][100])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout<<temp[i][j];
        cout<<endl;
    }
}

bool same(char temp[100][100])
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(temp[i][j]!=Map2[i][j])
                return false;
        }
    return true;
}

int ans()
{
    //-----------#1------
    char temp[100][100];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp[i][j]=Map[n-j+1][i];
    if(same(temp))
        return 1;
    //-----------#2-------
    char temp2[100][100];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp2[i][j]=temp[n-j+1][i];
    if(same(temp2))
        return 2;
    //---------#3-----
    char temp3[100][100];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp3[i][j]=temp2[n-j+1][i];
    if(same(temp3))
        return 3;
    //---------#4-----
    char oppo[100][100];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            oppo[i][j]=Map[i][n-j+1];
    if(same(oppo))
        return 4;
    //--------#5------
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp[i][j]=oppo[n-j+1][i];
    if(same(temp))
        return 5;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp2[i][j]=temp[n-j+1][i];
    if(same(temp2))
        return 5;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
                temp3[i][j]=temp2[n-j+1][i];
    if(same(temp3))
        return 5;
    //-------#6-----
    if(same(Map))
        return 6;
    //--------#7-----
    return 7;
}


int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> Map[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> Map2[i][j];
    cout << ans() << endl;
    return 0;
}
