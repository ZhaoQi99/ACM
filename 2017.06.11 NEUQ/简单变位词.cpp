/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<iostream>

typedef long long ll;

using namespace std;
bool isAnagram(char *str1, char *str2)
{
    //输入不合法
    if(str1 == NULL || str2 == NULL)
        return false;

    //创建哈希表，并且初始化哈希表
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(int i = 0;i<tableSize;i++)
        hashTable[i] = 0;

    char *pHashKey = str1;
    while(*pHashKey)
    {
        hashTable[*pHashKey]++;
        pHashKey ++;
    }

    char *pHashKey1 = str2;
    while(*pHashKey1)
    {
        hashTable[*pHashKey1]--;
        pHashKey1 ++;
    }

    if(hashTable[*pHashKey1] == 0)
    {
       return true;
    }
    else
        return false;
}
struct stu
{
    string a;
    bool temp=0;
};
int main( )
{
    cin.sync_with_stdio(false);
    struct stu x[30010];
    ll i=0;
    while(cin>>x[i++].a);
    for(ll k=0;k<i;k++)
    {

    }
    return 0;
}
