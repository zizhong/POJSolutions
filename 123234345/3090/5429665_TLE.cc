#include<stdio.h>
#include<stdlib.h>
#include<cmath>
double k[1000001];
int cmp(const void *a,const void *b)
{
    return *(double *)a>*(double *)b?1:-1;
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    int t=ncase;
    while(ncase--)
    {
        int size;
        scanf("%d",&size);
        printf("%d %d ",t-ncase,size);
        
        int h=0;
        for(int i=1;i<=size;i++)
        {
           for(int j=1;j<=size;j++)
           {
              k[h++]=j*1.0/i;
           }
        }        
        qsort(k,h,sizeof(k[0]),cmp);
        int num=3;
        for(int i=0;i<h-1;i++)
          if(fabs(k[i]-k[i+1])>1e-6) num++;
        
        printf("%d\n",num);
    }    
}




