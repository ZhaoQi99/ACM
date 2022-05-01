/*
Problem:
Author:赵旗
Data:2017-06-
Description:
Copyright  2017 赵旗. All rights reserved.
*/
#include<iostream>
#include<string>
#include<cstdio>
typedef long long ll;

using namespace std;

char map[(1<<10)+1][(2<<10)+1];
void print_map(int n)
{
    for (int i=1;i<=(1<<n);i++)
    {
        for (int j=1;j<=(1<<(n))+i;j++)
            printf("%c",map[i][j]);
        printf("\n");
    };
    return;
}

void print(int depth,int i0,int j0)
{
    if (depth==1)
    {
        map[1+i0][2+j0]='/';
        map[1+i0][3+j0]='\\';
        map[2+i0][1+j0]='/';
        map[2+i0][2+j0]='_';
        map[2+i0][3+j0]='_';
        map[2+i0][4+j0]='\\';
    }
    else
    {
        print(depth-1,i0,j0+(1<<(depth-1)));
        print(depth-1,i0+(1<<(depth-1)),j0);
        print(depth-1,i0+(1<<(depth-1)),j0+(1<<depth));
    }
    return;
}

int main()
{
    int n;
    while (scanf("%d",&n)&&n)
    {
        for (int i=1;i<=(1<<n);i++)
            for (int j=1;j<=(1<<(n+1));j++)
                map[i][j]=' ';
        print(n,0,0);
        print_map(n);
        printf("\n");
    }
    return 0;
}
