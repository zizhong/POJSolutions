#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float k[1000001];
int cmp(const void *a,const void *b)
{
    return *(float *)a>*(float *)b?1:-1;
}
int main()
{
    int ncase;
    int t;
    scanf("%d",&ncase);
    t=ncase;
    while(ncase--)
    {
        int size;        
        int h=0,i,j;
        int num=3;
        scanf("%d",&size);
        printf("%d %d ",t-ncase,size);
        for(i=1;i<=size;i++)
        {
           for(j=1;j<=size;j++)
           {
              k[h++]=j*1.0/i;
           }
        }        
        qsort(k,h,sizeof(k[0]),cmp);
        for(i=0;i<h-1;i++)
          if(fabs(k[i]-k[i+1])>1e-6) num++;        
        printf("%d\n",num);
    }    
}




