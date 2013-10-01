#include<stdio.h>
const int N = 5201,NIL=99999999;
int n,m,w,el;
struct E
{
       int s,e,t;
}e[N];
int Bellman(int x)
{
    int d[502]={0},p[502]={0};
    for(int i=1;i<=n;i++) if(i!=x)
           d[i]=NIL;
    while(d[x]>=0)
    {
         int flag=0;
         for(int i=0;i<el;i++)
             if(d[e[i].e]>d[e[i].s]+e[i].t)
             {
                   d[e[i].e]=d[e[i].s]+e[i].t;
                   p[e[i].e]=e[i].t;
                   flag=1;
             }
         if(!flag) return d[x]<0;
    }
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         el=0;
         scanf("%d%d%d",&n,&m,&w);
         for(int i=0;i<m;i++)
         {
              scanf("%d%d%d",&e[el].s,&e[el].e,&e[el].t);
              el++;
              e[el].s=e[el-1].e, e[el].e=e[el-1].s, e[el].t=e[el-1].t;
              el++;
         }
         for(int i=0;i<w;i++)
         {
              scanf("%d%d%d",&e[el].s,&e[el].e,&e[el].t);
              e[el].t=-e[el].t;
              el++;
         }
         int flag=0;
         for(int i=1;i<=n;i++)
            if(Bellman(i))
            {
                  flag=1;
                  break;
            }
         puts(flag?"YES":"NO");
    }
}
