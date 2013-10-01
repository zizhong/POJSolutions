#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=10001;
struct Line
{
       int s,t,p;
       bool start;
};
int n,ans,*level;
Line lx[N],ly[N];
inline int cmp(const void *a,const void *b)
{
     if(((Line *)a)->p == ((Line *)b)->p)
     {
          if(((Line*)a)->start) return -1;
          return 1;
     }
     return ((Line *)a)->p <((Line *)b)->p? -1:1;
}
void init()
{
     int x1,y1,x2,y2;
     ans=0;
     for(int i=1;i<=n;i++)
     {
         scanf("%d%d%d%d",&x1,&y2,&x2,&y1);
         lx[i*2-1].p=y1;
         lx[i*2-1].s=x1;
         lx[i*2-1].t=x2;
         lx[i*2-1].start=false;
         lx[i*2].p=y2;
         lx[i*2].s=x1;
         lx[i*2].t=x2;
         lx[i*2].start=true;
         ly[i*2-1].p=x1;
         ly[i*2-1].s=y2;
         ly[i*2-1].t=y1;
         ly[i*2-1].start=true;
         ly[i*2].p=x2;
         ly[i*2].s=y2;
         ly[i*2].t=y1;
         ly[i*2].start=false;         
     }
     n*=2;
     qsort(lx+1,n,sizeof(lx[0]),cmp);
     qsort(ly+1,n,sizeof(ly[0]),cmp);
     level=(int *)malloc(sizeof(int)*20002);
     level+=10000;
}
void scan(Line *l)
{
     for(int i=-10000;i<=10000;i++) level[i]=0;
     for(int i=1;i<=n;i++)
     {
          if(l[i].start)
          {
              for(int j=l[i].s;j<l[i].t;j++)
              {
                   level[j]++;
                   if(level[j]==1) ans++;
              }
          }else
          {
               for(int j=l[i].s;j<l[i].t;j++)
               {
                    level[j]--;
                    if(level[j]==0) ans++;
               }
          }
     }
}
int main()
{

    
    while(scanf("%d",&n)!=EOF)
    {
        init();
        scan(lx);
        scan(ly);
        printf("%d\n",ans);
    }
}
