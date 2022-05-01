/*
Problem:
Author:QiZhao
Data:2017-07-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long ll;

const int MAX=26;
struct Trie
{
    int num;
    Trie* next[MAX];
    Trie()
    {
        num=0;
        for(int i=0;i<MAX;i++)
            next[i]=NULL;
    }
};
Trie* root=new Trie;
void insert(char* word)
{
    Trie* p=root;
    int len=strlen(word);
    int m;
    for(int i=0;i<len;i++)
    {
        m=word[i]-'a';
        if(p->next[m]!=NULL)
        {
            p=p->next[m];
            ++(p->num);
        }
        else
        {
            Trie* temp=new Trie;
            ++(temp->num);
            p->next[m]=temp;
            p=temp;
        }
    }
}

int find(char* word)
{
    Trie* p =root;
    int len=strlen(word);
    int m;
    for(int i=0;i<len;i++)
    {
        m=word[i]-'a';
        if(p->next[m]==NULL)
            return 0;
        p=p->next[m];
    }
    return p->num;
}

int main()
{
    cin.sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    char str[26];
    while(gets(str))
    {
        if(str[0]=='\0')
            break;
        insert(str);
    }
    while(gets(str))
        cout<<find(str)<<endl;
    return 0;
}
