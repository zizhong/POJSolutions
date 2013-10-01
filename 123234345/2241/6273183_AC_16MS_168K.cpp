#include<stdio.h>
#include<stdlib.h>
const int N=100;
struct Tower
{
       int a,b,h;
}t[N];
int cmp(const void *a,const void *b)
{
    Tower *p1=(Tower *)a;
    Tower *p2=(Tower *)b;
    return p2->a - p1->a?p2->a - p1->a:p2->b - p1->b;
}
int _max(int a,int b){return a>b?a:b;}
int main()
{
    int n,T=0;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
         {
              int x,y,z;
              scanf("%d%d%d",&x,&y,&z);
              t[i*3+1].a=x,t[i*3+1].b=y,t[i*3+1].h=z;
              t[i*3+2].a=x,t[i*3+2].b=z,t[i*3+2].h=y;
              t[i*3+3].a=z,t[i*3+3].b=y,t[i*3+3].h=x;
         }
         n*=3;
         for(int i=0;i<=n;i++)
         {
              int k1=t[i].a,k2=t[i].b;
              if(k1>k2) t[i].a=k2,t[i].b=k1;
         }
         qsort(t+1,n+1,sizeof(t[0]),cmp);
         int f[N]={0};
         t[0].a=t[0].b=0x7fffffff;
         for(int i=0;i<=n;i++)
         {
              for(int j=0;j<=i;j++)
                  if(t[j].a>t[i].a&&t[j].b>t[i].b) f[i]=_max(f[i],f[j]+t[i].h);
         }
         int max=0;
         for(int i=0;i<=n;i++)
             if(max<f[i]) max=f[i];
         printf("Case %d: maximum height = %d\n",++T,max);
    }
}
