#include <iostream>
using namespace std;
struct a
{
    long long zhunkao;
    int shiji;
    int zuowei;
};
int main()
{
    int n;
    cin>>n;
    struct a stu[n];
    for(int i=0;i<n;i++)
        cin>>stu[i].zhunkao>>stu[i].shiji>>stu[i].zuowei;
    int  m,temp1,temp2;
    cin>>m;
    while(m--)
    {
        cin>>temp1;
        for(int i=0;i<n;i++)
            if(temp1==stu[i].shiji)
            {
            temp2=i;
            break;
            }
        cout<<stu[temp2].zhunkao<<" "<<stu[temp2].zuowei<<endl;
    }
    return 0;
}
