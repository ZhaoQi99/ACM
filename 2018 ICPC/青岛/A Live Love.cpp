#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t , m , n , mm;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(m == 0)
        {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        if(n == m)
        {
            cout << m << ' ' << m << endl;
            continue;
        }
        if(m <= (n - m))
        {
            cout << m << ' ' << 1 << endl;
            continue;
        }
        else
        {
            mm = m / (n - m + 1);
            if(m % (n - m+1) != 0)
                mm ++;
            cout << m << ' ' << mm << endl;;
        }
    }
    return 0;
}
