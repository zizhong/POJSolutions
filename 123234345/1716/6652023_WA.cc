#include<stdio.h>
#include<string.h>
const int N=10005;
struct E
{
       int s,e,w;
       E(int a=0,int b=0,int c=0)
       {s=a,e=b,w=c;}
}e[3*N];
int n,m,x,d[N];
void Bellman()
{
     int i,j;
     memset(d,0,sizeof(d));
     bool ok=true;
     for(i=0;ok&&i<n;i++)
     {
          ok=false;
          for(j=0;j<m;j++)
          if(d[e[j].e]<d[e[j].s]+e[j].w)
               d[e[j].e]=d[e[j].s]+e[j].w,ok=1;
     }     
}
int main()
{
    scanf("%d",&x);
    while(x--)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         if(n<b) n=b;
         e[m++]=(a,b+1,2);
    }
    n++;
    for(int i=1;i<=n;i++)
    {
         e[m++]=(i-1,i,0);
         e[m++]=(i,i-1,-1);
    }
    Bellman();
    printf("%d\n",d[n]);
}
