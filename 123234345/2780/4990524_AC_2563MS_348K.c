#include<stdio.h>
#include<stdlib.h>
#define NMAX ~(1<<31)
int cmp(const void*a,const void*b)
{
   return *(double *)a>*(double *)b?1:-1;
}
main()
{
   int n,i,j;
  while(scanf("%d",&n)!=EOF)
   {int ans=0;
   double a[2][1001]={0};
   int largest[1001]={0};
   for(i=0;i<n;i++)
      scanf("%lf%lf",&a[0][i],&a[1][i]);
   for(i=0;i<n;i++)
      {
      double k[1001]={0};
      int max=0,h=0,count=0;
      for(j=0;j<n;j++)
         {
           if(a[0][i]-a[0][j])
             k[j]=(a[1][i]-a[1][j])/(a[0][i]-a[0][j]);
           else
             k[j]=NMAX;
         }
      qsort(k,n,sizeof(k[0]),cmp);
      k[n-1]=-NMAX;
      double temp=-NMAX;
      for(h=0;h<n;h++)
      {
         if(temp==k[h])
            count++;
         else
         {
            temp=k[h];
            if(count>max)  max=count;
            count=1;
         }
      }
      largest[i]=max+1;  
      }      
   for(i=0;i<n;i++)
      if(ans<largest[i]) ans=largest[i];
   printf("%d\n",ans);}
}
