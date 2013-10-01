#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)&&n)
    {
         double a[1001]={0},b[1001]={0};
         for(int i=0;i<n;i++)   scanf("%lf",&a[i]);
         for(int i=0;i<n;i++)   scanf("%lf",&b[i]);
         double floor=0,ceiling=1;
         while(fabs(ceiling-floor)>1e-4)
         {
                 //if(ceiling<floor||fabs(ceiling-floor)<1e-5) break;
                 double  score[1001]={0};
                 double x=(floor+ceiling)*0.5;
                 for(int i=0;i<n;i++)  score[i]=a[i]-x*b[i];
                 qsort(score,n,sizeof(score[0]),cmp);
                 double tot=0;
                 for(int i=k;i<n;i++) tot+=score[i];
                 if(tot>=0)  floor=x;
                 else ceiling=x;
                 
         }
         printf("%d\n",(int)(100*floor+0.5));
    }
}
