#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
map<string,int> tree;
int main()
{
    char s[31];
    int n=0;
    while(gets(s))
    {
         tree[s]++;
         n++;
    }
    map<string,int>::iterator it;
    for(it=tree.begin();it!=tree.end();it++)
        printf("%s %.4f\n",it->first.c_str(),(it->second)*100.0/n);
}