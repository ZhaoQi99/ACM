/*
Problem:
Author:QiZhao
Data:2017-07-
Description:
Copyright  2017 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
char s[50004][26];
const ll MAX=26;
struct Trie
{
    bool flag;
    Trie* next[MAX];
};
void insert(Trie* root,char* word)
{
    Trie* p=root;
    while(*word!='\0')
    {
        if(p->next[*word-'a']==NULL)
        {
            Trie* temp=(Trie*)malloc(sizeof(Trie));
            for(ll i=0;i<MAX;i++)
                temp->next[i]=NULL;
            temp->flag=false;
            p->next[*word-'a']=temp;
        }
        p=p->next[*word-'a'];
        word++;
    }
    p->flag=true;
}
bool find(Trie* root,char *word)
{
    Trie*p =root;
    for(ll i=0;;i++)
    {
        if(word[i]=='\0')
            break;
        if(p==NULL||p->next[word[i]-'a']==NULL)
            return false;
        p=p->next[word[i]-'a'];
    }
    return p->flag;
}
int main()
{
    cin.sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    char str[30];
    Trie* root=(Trie*)malloc(sizeof(Trie));
    for(ll i=0;i<MAX;i++)
        root->next[i]=NULL;
    root->flag=false;
    ll count=0;
    while(scanf("%s",str)!=EOF)
    {
        strcpy(s[count++],str);
        insert(root,str);
    }
    for(ll i=0;i<count;i++)
    {
        for(ll j=1;j<strlen(s[i]);j++)
        {
            char temp1[30]={'\0'};
            char temp2[30]={'\0'};
            strncpy(temp1,s[i],j);
            strncpy(temp2,s[i]+j,strlen(s[i])-j);
            if(find(root,temp1)&&find(root,temp2))
            {
                cout<<s[i]<<endl;
                break;
            }
        }
    }
    return 0;
}

