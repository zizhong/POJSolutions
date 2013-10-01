#include<stdio.h>
void print(int x)
{
    putchar('{');
    for(int i=0;i<x;i++)
    {
         if(i) putchar(',');
         print(i);
    }
    putchar('}');
}
char s[1000*1000];
int a[16],sum[16],cnt[20000];
int num()
{
    gets(s);
    int i=0,t=0;
    for(;s[i];i++)
    {
         if(s[i]==',') t++;
    }
    if(t>0) return cnt[t];
    return i/2-1;
}
int main()
{
    for(int i=2;i<16;i++)
         a[i]=i-1+sum[i-1],cnt[a[i]]=i,sum[i]=a[i]+sum[i-1];
      
    int T;
    scanf("%d",&T);
    gets(s);
    while(T--)
    {
         print(num()+num()),puts("");
    }
}
