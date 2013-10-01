#include<stdio.h>
const int N=101,inf=0xfffffff,M=101;
int n,m;
struct E
{
       int s,e,w;
       E(int a=0,int b=0,int c=0){s=a,e=b,w=c;}
}e[M];
bool Bellman()
{
     int d[N],flag=0;
     for(int i=1;i<=n;i++) d[i]=inf;
     for(int i=1;i<n;i++)
     {
          flag=0;
          for(int j=0;j<m;j++)
              if(d[e[j].e]>d[e[j].s]+e[j].w)
                   d[e[j].e]=d[e[j].s]+e[j].w,flag=1;
          if(!flag) break;
     }
     for(int i=0;i<m;i++) if(d[e[i].e]>d[e[i].s]+e[i].w)
         return false;
     return true;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         scanf("%d",&m);
         int k=0;
         for(int i=0;i<m;i++)
         {
              int a,b,c;
              char s[3];
              scanf("%d%d%s%d",&a,&b,s,&c);
              if(s[0]=='g') e[k++]=E(a+b,a-1,-c-1);
              else e[k++]=E(a-1,a+b,c-1);
         }
         puts(Bellman()?"lamentable kingdom":"successful conspiracy");
    }
}
