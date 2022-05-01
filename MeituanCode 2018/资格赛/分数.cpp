/*
Problem:
Author:QiZhao
Data:2018-05-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k, c;
int w[505];
int score[505][505];
int flagi;
int flagj;//丢失数据的比赛的位置
int chuxian[505];
long double zongfen[505];
const long double EPS=1e-6;

int find(int j)
{
    //第J场比赛的最高分
    int flag = -0xffff;
    for(int i = 1; i <= n; i++)
    {
        if(score[i][j] > flag)
        {
            flag = score[i][j];
        }
    }
    //cout<<flag<<endl;
    return flag;
}

struct stu
{
    long double score;
    int index;
    stu(long double a, int b)
    {
        score = a;
        index = b;
    }
};

bool operator <(const stu& s1, const stu&s2)
{
        return s1.score < s2.score;
}

void Setchuxian(long double  a[])
{
    vector<stu> s;
    for(int i = 1; i <= n; i++)
    {
        stu temp(a[i], i);
        s.push_back(temp);
    }
    sort(s.begin(), s.end());
    vector<stu>::iterator t = s.end() - 1;
    double flag = s[n - k].score;
    int cnt = 0;
    for(int i = n - k - 1; i >= 0; i--)
    {
        if( abs(flag - s[i].score)<EPS)
            cnt++;
    }
    if(cnt == 0)
    {
        for(int i = 1; i <= k; i++)
        {
            chuxian[t->index] += 2;
            t--;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            //cout<<t->score<<endl;
            if(abs(flag-t->score)<EPS)
                chuxian[t->index] += 1;
            else if((t->score - flag)>EPS)
                chuxian[t->index] += 2;
            t--;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    memset(chuxian, 0, sizeof(chuxian));
    cin >> n >> m >> k >> c;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> score[i][j];
            if(score[i][j] == -1)
            {
                flagi = i;
                flagj = j;
            }
        }
    }
    memset(zongfen, 0, sizeof(zongfen));
    int fuck=0;
    for(int j = 1; j <= m; j++)
    {
        int MAX = find(j);
        if(j==flagj)
            fuck=MAX;
        if(j == flagj)
            continue;

        if(MAX == 0)
            continue;
        for(int i = 1; i <= n; i++)
        {
            zongfen[i] += w[j] * score[i][j]*1.0/(MAX*1.0);
            //cout<<zongfen[i];
        }

    }
    for(int i = 0; i <= c; i++)
    {
        long double zongfen_temp[505];
        score[flagi][flagj] = i;
        if(i==fuck)///WA
        {
            score[flagi][flagj] = fuck-1;
        }
        int MAX = find(flagj);
        if(MAX == 0)//都是0
        {
            Setchuxian(zongfen);
        }
        else
        {
            for(int j = 1; j <= n; j++)
            {
                zongfen_temp[j] = zongfen[j] + w[flagj] * score[j][flagj]*1.0/(MAX*1.0);
            }
            Setchuxian(zongfen_temp);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        //cout<<chuxian[i]<<endl;
        if(chuxian[i] ==  (2*c+2 ))
            cout << 1 << endl;
        else
        {
            if(chuxian[i] == 0)
                cout << 2 << endl;
            else
                cout << 3 << endl;
        }
    }
    return 0;
}
/*
4 2 2 100
1 1
100 99
70 70
40 -1
100 39
*/
