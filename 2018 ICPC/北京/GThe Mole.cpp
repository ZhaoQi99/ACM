/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}

struct point
{
    int x;
    int y;
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    point()
    {
        x=0;
        y=0;
    }
};
struct tunnel
{
    point a;
    point b;
    tunnel(point aa,point bb)
    {
        a=aa;
        b=bb;
    }
};

double PointTOline( point const&a, point const&b, point const&p)
{
    double ap_ab = (b.x - a.x) * (p.x - a.x) + (b.y - a.y) * (p.y - a.y); //cross( a , p , b );
    if ( ap_ab <= 0 )
        return sqrt( (p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y) );

    double d2 = ( b.x - a.x ) * ( b.x - a.x ) + ( b.y - a.y ) * ( b.y - a.y ) ;
    if ( ap_ab >= d2 )
        return sqrt( (p.x - b.x ) * ( p.x - b.x ) + ( p.y - b.y ) * ( p.y - b.y ) ) ;

    double r = ap_ab / d2;
    double px = a.x + ( b.x - a.x ) * r;
    double py = a.y + ( b.y - a.y ) * r;
    return sqrt( (p.x - px) * (p.x - px) + (p.y - py) * (p.y - py) );
}
double PointTOTunnel(tunnel const &t,point const &p)
{
    return PointTOline(t.a,t.b,p);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<tunnel> v;
    forn(i,n)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        point x(x1,y1);
        point y(x2,y2);
        tunnel tt(x,y);
        v.push_back(tt);
    }
    vector<tunnel>::iterator t;
    forn(i,m)
    {
        int x,y;
        int flag=1;
        double len=0xffff;
        int ans=0;
        cin>>x>>y;
        point p(x,y);
        for(t=v.begin();t!=v.end();t++)
        {
            double temp=PointTOTunnel(*t,p);
            if(temp<len)
            {
                len=temp;
                ans=flag;
            }
            flag++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
