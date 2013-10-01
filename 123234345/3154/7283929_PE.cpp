#include<stdio.h>
#include<stdlib.h>
const double L=10000.0;
struct Node
{
       double d;
       int id;
}a[1001*3];
double min(double x,double y){return x>y?y:x;}
int cmp(const void *a,const void *b)
{
    return ((Node *)a)-> d > ((Node *)b)->d?1:-1;
}
double mind(int i,int j)
{
       double x=a[i].d,y=a[j].d;
       if(y<x){double t=x;x=y;y=t;}
       return min(y-x,1-y+x);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    m+=n;
    for(int i=0;i<n;i++)
    {
          a[i].id=1;
          a[i].d=(1.0*i)/n;
    }
    for(int i=0;i<m;i++)
    {
         a[n+i].id=0;
         a[n+i].d=(1.0*i)/m;
    }
    qsort(a,n+m,sizeof(a[0]),cmp);
    double sum=0;
    for(int i=0;i<n+m;i++) if(a[i].id==1)
    {
         int t1=i+1==n+m?0:i+1;
         int t2=i-1<0?n+m-1:i-1;
         double ans=mind(i,t2);
         if(ans>mind(t1,i)) ans=mind(t1,i);
         sum+=ans*L;
    }
    printf("%lf\n",sum);
}
