#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int judge1(int x)
{
	while(x>1)
	{
		x--;
	}
	if(x>0) return 1;
	else return 0;
}
int judge2(char X[10000],int &y)
{
    for(int i=0;i<strlen(X);i++)
    {
        if(X[i]<48||X[i]>57)
            return 0;
    }
    y=atoi(X);
    if(judge1(y)==0)return 0;
    return 1;
}
int main()
{
    char A[10000],B[10000];
	int a,b,flag1=0,flag2=0;
	scanf("%s",&A);
	getchar();
    gets(B);
    flag2=judge2(A,a);
	if(a<=10000&&a>=1&&flag2==1)
		cout<<a;
	else {cout<<"?";flag1=1;}
	cout<<" + ";
	flag2=0;
    flag2=judge2(B,b);
	if(b<=10000&&b>=1&&flag2==1)
		cout<<b;
	else {cout<<"?";flag1=1;}
	cout<<" = ";
	if(flag1==1) cout<<"?";
	else cout<<a+b;
	cout<<endl;
    return 0;
}
