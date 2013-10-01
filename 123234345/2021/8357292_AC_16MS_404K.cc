#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=110;
struct Node
{
       char name[N];
       int age;
}d[N];
int len=0,map[N][N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a;
    Node *p2=(Node *)b;
    if(p1->age==p2->age)
        return strcmp(p1->name,p2->name);
    return p2->age-p1->age;
}
int  find(char s[])
{
     int idx=0;
     for(;idx<len&&strcmp(s,d[idx].name);idx++) ;
     if(idx>=len)
     {
          strcpy(d[len].name,s);
          idx=len;
          len++;
     }
     return idx;
}
void dfs(int x)
{
     for(int i=0;i<len;i++)
     {
          if(map[x][i])
          {
               d[i].age=d[x].age-map[x][i];
               dfs(i);
          }
     }
}
int main()
{
    strcpy(d[len].name,"Ted");
    d[len].age=100;
    ++len;
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
            
            memset(map,0,sizeof(map));
            len=1;
            int w,x;
            scanf("%d",&x);
            char n1[N],n2[N];            
            for(int i=0;i<x;i++)
            {
                scanf("%s%s%d",n1,n2,&w);
                int u=find(n1),v=find(n2);
                map[u][v]=w;
            }
            //for(int i=0;i<len;i++,puts(""))
            //   for(int j=0;j<len;j++) printf("%d ",map[i][j]);
            dfs(0);
            qsort(d+1,len-1,sizeof(d[0]),cmp);
            printf("DATASET %d\n",tt);
            for(int i=1;i<len;i++)
                 printf("%s %d\n",d[i].name,d[i].age);
    }
}
