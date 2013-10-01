#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int N=22;
double len[N];
int cmp(const void *a,const void *b)
{
    return *(double *)a >*(double *)b?1:-1;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
            scanf("%lf",&len[i]);
         if(n==1) puts("NO");
         else if(n==2)
         {
              if(fabs(len[0]-len[1])<1e-8) puts("YES");
              else puts("NO");
         }
         if(n<3) continue;
         qsort(len,n,sizeof(len[0]),cmp);
         int flag=0;
         double sum=len[0]+len[1];
         for(int i=2;i<n;i++)
         {
             sum+=len[i];
             if(sum-len[i]>len[i]||fabs(sum-2*len[i])<1e-8)
             {
                  flag=1;
                  //printf("%lf %lf\n",sum-len[i],len[i]);
                  break;
             }
         }
         puts(flag?"YES":"NO");
    }
}
