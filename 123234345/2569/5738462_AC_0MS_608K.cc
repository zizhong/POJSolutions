#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Dig
{
       char c1,c2;
       int n;
}d[6000];
int cmp(const void *a,const void *b)
{
    Dig* p1=(Dig*)a;
    Dig* p2=(Dig*)b;
    if(p1->n!=p2->n) return p2->n - p1->n;
    if(p1->c1!=p2->c1) return p1->c1 - p2->c1;
    return p1->c2 - p2->c2;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         char s[6000],s1[100];
         s[0]=0;
         gets(s1);
         for(int i=0;i<n;i++)
         {
                 gets(s1);
                 strcat(s,s1);
         }
         //init
         int len=strlen(s);
         for(int i=0;i<len;i++)  d[i].c1=d[i].c2=d[i].n=0;
         //deal
         //for(int i=0;i<len;i++)  if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
         int idx=0;
         for(int i=1;i<len;i++)
         {       
                 int j=0;
                 for(;j<idx;j++)
                     if(s[i-1]==d[j].c1&&s[i]==d[j].c2)
                     {
                          d[j].n++;
                          break;
                     }
                 if(j==idx)
                     d[j].c1=s[i-1],d[j].c2=s[i],d[j].n=1,idx++;
         }
         qsort(d,idx,sizeof(d[0]),cmp);
         for(int i=0;i<5;i++)
         {
             double f=d[i].n*1.0/(len-1);
             printf("%c%c %d %.6f\n",d[i].c1,d[i].c2,d[i].n,f);
         }
         puts("");
    }
}
