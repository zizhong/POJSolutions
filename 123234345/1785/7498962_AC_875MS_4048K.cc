#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=50010;
struct Node
{
       char s[25];
       int d;
}node[N];
int n;
int cmp(const void *a,const void *b)
{
    return strcmp(((Node *)a)->s,((Node *)b)->s);
}
int pre[N],rc[N],lc[N];
void dfs(int i)
{
     putchar('(');
     if(lc[i]!=-1) dfs(lc[i]);
     printf("%s/%d",node[i].s,node[i].d);
     if(rc[i]!=-1) dfs(rc[i]);
     putchar(')');
}
int main()
{
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
         {
              scanf("%s",node[i].s);
              int j=0,d;
              for(;node[i].s[j]-'/';j++) ;
              node[i].s[j++]=0;
              for(d=0;node[i].s[j];j++) d=d*10+node[i].s[j]-'0';
              node[i].d=d;             
         }
         qsort(node,n,sizeof(node[0]),cmp);
         int p=0,r=0;
         pre[p]=rc[p]=lc[p]=-1;
         for(int i=1;i<n;i++)
         {
              int x=i-1;
              pre[i]=rc[i]=lc[i]=-1;
              while(x!=-1)
              {
                   if(node[x].d>node[i].d)
                   {
                         lc[i]=rc[x];
                         pre[i]=x;
                         rc[x]=i;
                         if(x==p) p=i;
                         break;
                   }
                   pre[i]=pre[x];
                   rc[x]=lc[i];
                   lc[i]=x;
                   x=pre[x];                  
              }
              if(pre[i]==-1) r=i;
              
         }
         dfs(r);
         puts("");
    }
}
