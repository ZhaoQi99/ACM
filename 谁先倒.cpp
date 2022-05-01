#include <iostream>
using namespace std;
int main()
{
    int max1,max2;
    cin>>max1>>max2;
    int n,jia(0),yi(0),loop(0);
    cin>>n;
    int a[n],b[n],c[n],d[n];
    for(int i=0;i<n,loop!=1;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        if((a[i]+c[i]==b[i])&&(a[i]+c[i]==d[i])) ;
            else
            {
                if(a[i]+c[i]==b[i]) jia++;
                if(a[i]+c[i]==d[i]) yi++;
                if(jia>max1){cout<<'A'<<endl;cout<<yi;loop=1;}
                if(yi>max2){cout<<'B'<<endl;cout<<jia;loop=1;}
            }
    }
    return 0;
}
