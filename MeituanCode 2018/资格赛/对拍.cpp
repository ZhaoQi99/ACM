#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
    int t = 100000;
    while(t--)
    {
        system("random.exe > data.txt");
        system("第四.exe < data.txt > 1.txt");
        system("分数.exe < data.txt > 2.txt");
        if(system("fc 2.txt 1.txt"))
            break;
    }
    if(t == 0)
        cout << "no error" << endl;
    else
        cout << "error" << endl;
    return 0;
}
