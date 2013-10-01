#include<stdio.h>
#define NIL 99999999
double k[20000];
int x[201],y[201];
int cmp(const void *a,const void *b)
{
    return *(double *)a > *(double *)b ? 1 : -1;
}
int main()
{
    int n,i,j,h=0,count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
       {
          if(x[i]==x[j]) k[h++]=NIL;
          else k[h++]=(1.0*(y[j]-y[i])/(x[j]-x[i]));
       }
    qsort(k,h,sizeof(double),cmp);
    count=1;
    for(i=1;i<h;i++)
    {
       while((k[i]-k[i-1])<1e-8) i++;
       if(i<h) count++;
    }
    printf("%d\n",count);
}
