#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=1001,inf=0xfffffff;
struct Node
{
     int x1,x2,h;
}bd[N];
int cmp(const void *a,const void *b)
{
    return ((Node *)b)->h - ((Node *)a)->h;
}
int min(int a,int b){return a>b?b:a;}
int g[N][2],max,n;
int f[N][2];
int cal(int b,int x)
{
    if(bd[b].h==0) return 0;
    if(f[b][0]==-1) f[b][0]=cal(g[b][0],bd[b].x1)+bd[b].h-bd[g[b][0]].h;
    if(bd[b].h-bd[g[b][0]].h>max) f[b][0]=inf;
    if(f[b][1]==-1) f[b][1]=cal(g[b][1],bd[b].x2)+bd[b].h-bd[g[b][1]].h;
    if(bd[b].h-bd[g[b][1]].h>max) f[b][1]=inf;
    return min(f[b][0]+x-bd[b].x1,f[b][1]+bd[b].x2-x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int x,y;
         scanf("%d%d%d%d",&n,&x,&y,&max);
         bd[0].x1=-inf,bd[0].x2=inf,bd[0].h=0;
         for(int i=1;i<=n;i++)
             scanf("%d%d%d",&bd[i].x1,&bd[i].x2,&bd[i].h);
         qsort(bd,n+1,sizeof(bd[0]),cmp);
         for(int i=0;i<n;i++)
         {
             for(int j=i+1;j<=n;j++)
                 if(bd[j].h<bd[i].h&&bd[i].x1>=bd[j].x1&&bd[i].x1<=bd[j].x2)
                 {
                      g[i][0]=j;
                      break;
                 }
             for(int j=i+1;j<=n;j++)
                 if(bd[j].h<bd[i].h&&bd[i].x2>=bd[j].x1&&bd[i].x2<=bd[j].x2)
                 {
                      g[i][1]=j;
                      break;
                 }
         }
         int st=0;
         for(int i=0;i<=n;i++)
         {
             if(bd[i].h<=y&&bd[i].x1<=x&&bd[i].x2>=x)
             {
                  st=i;
                  break;
             }
         }
         memset(f,-1,sizeof(f));
         printf("%d\n",cal(st,x)+y-bd[st].h);
    }
}
