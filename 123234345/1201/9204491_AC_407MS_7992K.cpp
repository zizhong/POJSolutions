#include<stdio.h>
#include<string.h>
const int N=500005;
int n,d[N];
struct EDGE
{
       int u,v,w;
       EDGE(int a=0,int b=0,int c=0){u=a,v=b,w=c;}
}e[N];
void Bellman(int flag,int m)
{
     bool mark;
     int i,j;
     memset(d,63,sizeof(d));
     for(i=0;i<=n;i++)
     {
          mark=true;
          for(j=0;j<flag;j++)
          {
               if(d[e[j].u]+e[j].w<d[e[j].v])
                   d[e[j].v]=d[e[j].u]+e[j].w,mark=false;
          }
          if(mark) break;
     }
}
int main()
{
    int i,j,flag,m,a,b,c;
    while(scanf("%d",&m)!=EOF)
    {
         flag=0;
         n=-1;
         for(i=0;i<m;i++)
         {
              scanf("%d%d%d",&a,&b,&c);
              e[flag++]=EDGE(b,a-1,-c);
              if(n<b) n=b;
         }
         for(i=1;i<=n;i++)
         {
              e[flag++]=EDGE(i,i-1,0);
              e[flag++]=EDGE(i-1,i,1);
         }
         Bellman(flag,m);
         printf("%d\n",d[n]-d[0]);
    }
}