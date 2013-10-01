#include<stdio.h>
#include<string.h>
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
     memset(d,0,sizeof(d));
     for(int i=0;i<n;i++)
     {
          flag=0;
          for(int j=0;j<m;j++)
              if(d[e[j].e]>d[e[j].s]+e[j].w)
                   d[e[j].e]=d[e[j].s]+e[j].w,flag=1;
     }
     return flag;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         scanf("%d",&m);
         int k=0;
         n++;
         for(int i=0;i<m;i++)
         {
              int a,b,c;
              char s[3];
              scanf("%d%d%s%d",&a,&b,s,&c);
              if(s[0]=='g') e[k++]=E(a+b+1,a,-c-1);
              else e[k++]=E(a,a+b+1,c-1);
         }
         puts(!Bellman()?"lamentable kingdom":"successful conspiracy");
    }
}
