#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int N=1001;
struct Point{double x,y;}p[N];
struct Line{double x,y;}line[N];
int cmp(const void *a,const void *b)
{
    return ((Point *)a)->x > ((Point *)b)->x?1:-1;
}
int cmp2(const void *a,const void *b)
{
    return ((Line *)a)->x > ((Line *)b)->x?1:-1;
}
int ok(int i,int k,int d)
{
    return line[i].x<=line[k].x&&line[k].y<=line[i].x+2*d;
}
int main()
{
    int T=0,n,d;
    while(scanf("%d%d",&n,&d),n)
    {
         int flag=1;
         for(int i=0;i<n;i++)
         {
             scanf("%lf%lf",&p[i].x,&p[i].y);
             if(p[i].y>d) flag=0;
         }
         printf("Case %d: ",++T);
         if(flag==0)
         {
               puts("-1");
               continue;
         }
         qsort(p,n,sizeof(p[0]),cmp);
         for(int i=0;i<n;i++)
         {
               line[i].x=p[i].x-(d-sqrt(d*d-p[i].y*p[i].y));
               line[i].y=p[i].x+(d-sqrt(d*d-p[i].y*p[i].y));
         }
         qsort(line,n,sizeof(line[0]),cmp2);
         int v[N]={0};
         int ans=0;
         for(int i=0;i<n;i++) if(v[i]==0)
         {
               ans++;
               int k=i;
               while(k<n&&ok(i,k,d)) v[k]=1,k++;
         }
         printf("%d\n",ans);
    }
}
