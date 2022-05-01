#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int t = rand() % 20+1;
    cout << t << endl;
    while(t--)
    {
        int n=rand()%10+1;
        int x=rand()%9+1;
        cout<<n<<" "<<x<<endl;
        for(int i=0;i<n;i++)
        {
            int temp=rand()%9+1;
            cout<<temp;
            if(i!=n-1)
                cout<<" ";
        }
        cout<<endl;
                for(int i=0;i<n;i++)
        {
            int temp=rand()%9+1;
            cout<<temp;
            if(i!=n-1)
                cout<<" ";
        }
        cout<<endl;
    }
}
