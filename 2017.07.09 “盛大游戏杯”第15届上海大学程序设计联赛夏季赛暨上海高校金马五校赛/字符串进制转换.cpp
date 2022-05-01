//WA
/*
Problem:
Author:赵旗
Data:2017-07-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

/*将一个整型数字转化成字符型数字，例如 8->'8'，12->'c'*/
char numToChar(char num)
{
	/*num是0到9之间的数字*/
	if(num<=9&&num>=0)
	{
		num+=48;
	}

	/*num是10到15之间的数字*/
	else
	{
		switch(num)
		{
		case 10:num='A';
		case 11:num='B';
		case 12:num='C';
		case 13:num='D';
		case 14:num='E';
		case 15:num='F';
		}
	}
	return num;
}

/*将一个字符型数字转化成整型数字，例如 '8'->8，'c'->12*/
ll charToNum(char &num)
{
	/*num是0到9之间的字符型数字*/
	if(num<='9'&&num>='0')
	{
		num-=48;
	}

	/*num是'A'到'F'之间的字符型数字*/
	else
	{
		switch(num)
		{
		case 'A':
		case 'a':
			num=10;
		case 'B':
		case 'b':
			num=11;
		case 'C':
		case 'c':
			num=12;
		case 'D':
		case 'd':
			num=13;
		case 'E':
		case 'e':
			num=14;
		case 'F':
		case 'f':
			num=15;
		}
	}
	return num;
}

/*将任意进制整数转化为十进制整数，返回转化后的十进制整数，num为任意进制整数，binary为该整数的进制*/
ll anyBinaryToDecimal(string num,ll binary)
{
	ll len=num.size();
	ll decimal_num=0;
	for(ll i=0;i<len;i++)
	{
		decimal_num+=charToNum(num[i])*pow(binary,len-i-1);
	}
	return decimal_num;
}

/*将十进制转化为任意进制，decimal为十进制整数，binary为需要转化的进制*/
void decimalToAnyBinary(ll decimal,ll binary)
{
	string result;//保存x进制数
	char temp;
	while(decimal>0)
	{
		temp=decimal%binary;
		result+=numToChar(temp);
		decimal=decimal/binary;
	}

	/*输出转化后的x进制整数*/
	for(ll i=result.size()-1;i>=0;i--)
		cout<<result[i];
	cout<<endl;
}

int main( )
{
    cin.sync_with_stdio(false);
    string s;
    cin>>s;
    ll m;
    cin>>m;
    for(ll i=0;i<s.length();i++)
        s[i]=s[i]-49;
	ll decimal_num=anyBinaryToDecimal(s,26);//将十六进制数转化成十进制数
    decimalToAnyBinary(decimal_num,m);//将十进制数转化成八进制数，并输出结果
    return 0;
}
