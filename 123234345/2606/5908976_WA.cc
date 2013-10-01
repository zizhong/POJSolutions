#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
double k[40000];
int x[201],y[201],nk;
int main()
{
    int n;
    scanf("%d",&n);
    {
        for(int i=0;i<n;i++)
           scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<n;i++)
           for(int j=i+1;j<n;j++)
               if(x[i]==x[j]) k[nk++]=0.0;
               else k[nk++]=(y[i]-y[j])*1.0/(x[i]-x[j]);
        qsort(k,nk,sizeof(k[0]),cmp);
        int ans=1,t=1;
        double tk=k[0];
        k[nk]=k[nk-1]-1;
        for(int i=1;i<=nk;i++)
        {
             if(fabs(tk-k[i])<1e-8) t++;
             else
             {
                 if(t>ans) ans=t;
                 t=1;
                 tk=k[i];
             }
        }
        printf("%d\n",ans/2);
    }}
