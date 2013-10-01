#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define NMAX 9999999
int cmp(const void *a,const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
int x[201],y[201],nk;
int main()
{
    int n;
    scanf("%d",&n);
    {
        for(int i=0;i<n;i++)
           scanf("%d%d",&x[i],&y[i]);
        int sum=0;
        for(int i=0;i<n;i++)
        {
           double k[201];
           for(int j=0;j<n;j++)
               if(x[i]==x[j]) k[j]=NMAX;
               else k[j]=(y[i]-y[j])*1.0/(x[i]-x[j]);
        qsort(k,n,sizeof(k[0]),cmp);
        int ans=0,t=1;
        double tk=k[0];
        k[n]=k[n-1]-1;
        for(int j=1;j<n;j++)
        {
             if(fabs(tk-k[j])<1e-8) t++;
             else
             {
                 if(t>ans) ans=t;
                 t=1;
                 tk=k[j];
             }
        }
        if(sum<ans) sum=ans;
        }
        printf("%d\n",sum+1);
    }
    }

