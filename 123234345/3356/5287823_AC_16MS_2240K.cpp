#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
short f[1001][1001];
int main()
{
    char a[1001],b[1001];
    int na,nb;
    while(scanf("%d%s%d%s",&na,a+1,&nb,b+1)!=EOF)
    {
        int i,j;
        for(i=0;i<=1000;i++) f[i][0]=f[0][i]=i;
        for(i=1;i<=na;i++)
           for(j=1;j<=nb;j++)
           f[i][j]=min(min(f[i][j-1]+1,f[i-1][j]+1),f[i-1][j-1]+(a[i]!=b[j]));
        cout<<f[na][nb]<<endl;
    }
}
