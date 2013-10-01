#include<stdio.h>
#include<stdlib.h>
const int N=101;
int g[N][N];
int pp[41][2],v[N];
int n,m;
int w,s,p;
int ok(int x)
{
    for(int i=1;i<=n;i++)
       if(v[i]==x) return 0;
    for(int i=0;i<p;i++)
       if(x==pp[i][0]||x==pp[i][1])
           return 0;
    return 1;
}
struct Node
{
       int key;
       int id;
       int ix;
}node[N];
int cmp(const void *a,const void *b)
{
    return ((Node *)a)->key - ((Node *)b)->key;
}
int min(int a,int b){return a>b?b:a;}
int main()
{
    while(scanf("%d",&w),w)
    {
         scanf("%d%d",&s,&p);
         n=0;
         v[++n]=0;
         node[1].key=0;
         node[1].id=-1;
         node[1].ix=n;
         for(int i=0;i<p;i++)
         {
              scanf("%d%d",&pp[i][0],&pp[i][1]);
              v[++n]=pp[i][1];
              node[n].key=pp[i][1];
              node[n].id=-1;
              node[n].ix=n;
         }  
         for(int i=0;i<p;i++)
         {
             if(!ok(pp[i][0]-1))  continue;
             v[++n]=pp[i][0]-1;
             node[n].id=-1;
             node[n].key=pp[i][0]-1;
             node[n].ix=n;
         }
         v[++n]=w;
         node[n].id=-1;
         node[n].key=w;
         node[n].ix=n;
         int m=n;
         for(int i=0;i<p;i++)
         {
              int flag=1;   
             for(int j=1;j<=m&&flag;j++)
                 if(node[j].key==pp[i][0])
                    flag=0;
             if(flag)
             {
                  m++;
                  node[m].key=pp[i][0];
                  node[m].id=i;
                  node[m].ix=m;
             }
         }
         qsort(node+1,m,sizeof(node[1]),cmp);
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j) g[i][j]=0x3ffffff0;
         for(int i=1;i<=n+p;i++) if(node[i].id==-1)
              for(int j=i+1;j<=n+p;j++)
              {      
                                  
                     int w=node[j].key-node[i].key;
                     w=w/s+(w%s?1:0);
                     if(node[j].id==-1)
                     {
                          if(g[node[i].ix][node[j].ix]>w)g[node[i].ix][node[j].ix]=w;
                     }
                     else
                     {
                          int b=node[j].id+2;
                          if(g[node[i].ix][b]>w)  g[node[i].ix][b]=w;
                          if((node[j].key-node[i].key)%s==0) break;
                     }
              }
         int d[N]={0},v[N]={0};
         for(int i=1;i<=n;i++) d[i]=g[1][i];
         d[1]=0,v[1]=1;
         while(1)
         {
               int min=0x3ffffff0,tail=-1;
               for(int i=1;i<=n;i++)
                  if(v[i]==0&&min>d[i])
                  {
                       min=d[i];
                       tail=i;
                  }
               if(tail==-1) break;
               v[tail]=1;
               for(int i=1;i<=n;i++)
                   if(v[i]==0&&d[tail]+g[tail][i]<d[i])
                        d[i]=d[tail]+g[tail][i];
         }
         printf("%d\n",d[n]);
    }
}
