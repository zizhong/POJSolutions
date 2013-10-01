#include<stdio.h>
#include<string.h>
const int N=31;
const double eps=1e-8;
struct E
{
       int s,e;
       double rate;
}e[N*N];
int n,m,t;
char Cur[N][82];
int Find(char *s)
{
    int i=0;
    while(strcmp(Cur[i],s)) i++;
    return i;
}
int Bellman(int x)
{
    double d[N]={0};
    d[x]=1;
    while(d[x]<=1+eps)
    {
         int flag=0;
         for(int i=0;i<m;i++)
             if(d[e[i].e]<d[e[i].s]*e[i].rate)
             {
                   d[e[i].e]=d[e[i].s]*e[i].rate;
                   flag=1;
             }
         if(!flag) return d[x]>1+eps;
    }
    return 1;
}
int main()
{    
    while(scanf("%d",&n),n)
    {
         getchar();
         for(int i=0;i<n;i++) gets(Cur[i]);
         scanf("%d",&m);         
         for(int i=0;i<m;i++)
         {
              char s1[82],s2[82];
              double rate;
              scanf("%s%lf%s",s1,&rate,s2);
              e[i].s=Find(s1),e[i].e=Find(s2),e[i].rate=rate;
         }
         int flag=0;
         for(int i=0;i<n;i++) if(Bellman(i))
         {
                 flag=1;
                 break;
         }
         printf("Case %d: %s\n",++t,flag?"Yes":"No");
    }
}
