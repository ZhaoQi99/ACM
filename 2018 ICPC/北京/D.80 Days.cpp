#include <bits/stdc++.h>
#define maxn  1000006
using namespace std;

typedef long long  ll;

ll a[maxn];
ll b[maxn];
ll num[maxn];
bool flag=false;

int main()
{
    int t;
    scanf("%d",&t);
    int n,c;
    while(t--)
    {
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }

        for(int i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
            num[i]=a[i]-b[i];
        }

        ll res=c+num[0];
        int bg=1;
        int len=1;
        while(bg!=0)
        {
            if(len==n)
            {
                if(res>=0)
                {
                    flag=true;
                    break;
                }
            }

            if(res>=0)
            {
                res+=num[(len+bg-1)%n];
                len++;
            }
            else
            {
                res-=num[(bg+n-1)%n];
                bg++;
                bg%=n;
                len--;
            }
        }
        if(flag)
        {
            printf("%d\n",(bg+n-1)%n+1);
        }
        else
            printf("-1\n");
    }

    return 0;

}
