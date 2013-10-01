#include<stdio.h>
#include<string.h>
const int M=100001,N=1001,inf=0xffffff;
int d[N],n,m;
struct E
{
       int u,v,w;
       E(int a=0,int b=0,int c=0){u=a,v=b,w=c;}
}e[2*M];
bool Bellman(int s)
{
     for(int i=1;i<=n;i++) d[i]=inf;
     d[s]=0;
     int flag;
     for(int i=1;i<=n;i++)
     {
          flag=0;
          for(int j=0;j<m;j++)
              if(d[e[j].v]>d[e[j].u]+e[j].w)
                   d[e[j].v]=d[e[j].u]+e[j].w,flag=1;
          if(!flag) break;
     }
     for(int i=0;i<m;i++)
         if(d[e[i].v]>d[e[i].u]+e[i].w) return false;
     return true;
}
int main()
{
    int y;
    while(scanf("%d%d",&n,&y)!=EOF)
    {
         char s[2];
         m=0;
         int a,b,c;
         for(int i=0;i<y;i++)
         {
              scanf("%s",s);
              if(s[0]=='P')
              {
                   scanf("%d%d%d",&a,&b,&c);
                   e[m++]=E(b,a,c);
                   e[m++]=E(a,b,-c);
              }
              else
              {
                  scanf("%d%d",&a,&b);
                  e[m++]=E(a,b,-1);
              }
         }
         puts(Bellman(1)?"Reliable":"Unreliable");
    }
}
