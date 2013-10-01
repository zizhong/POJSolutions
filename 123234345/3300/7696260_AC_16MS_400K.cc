#include<stdio.h>
#include<stdlib.h>
const int N=11;
int f[N],r[N];
double v[N*N];
int cmp(const void *a,const void *b)
{
    return *(double *)a > *(double *)b?1:-1;
}
int main()
{
    int n,m;
    while(scanf("%d",&n),n)
    {
         scanf("%d",&m);
         for(int i=0;i<n;i++) scanf("%d",&f[i]);
         for(int i=0;i<m;i++) scanf("%d",&r[i]);
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                 v[i*m+j]=r[j]*1.0/f[i];
         qsort(v,n*m,sizeof(v[0]),cmp);
         double ans=0;
         for(int i=1;i<n*m;i++)
         {
              if(ans<v[i]/v[i-1]) ans=v[i]/v[i-1];
         }
         printf("%.2f\n",ans);
    }
}
