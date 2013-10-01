#include<stdio.h>
#include<stdlib.h>
const int N=1001;
int t[N],k[N];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n,total,i,j,s;
    while(scanf("%d",&n),n)
    {
         for(i=0;i<n;i++) scanf("%d",&t[i]);
         for(i=0;i<n;i++) scanf("%d",&k[i]);
         qsort(t,n,sizeof(t[0]),cmp);
         qsort(k,n,sizeof(k[0]),cmp);
         total=0;
         int tail=n-1,tail2=n-1,head=0;
         for(i=0;i<n;i++)
         {
             if(k[i]<t[head]) total+=200,++head;
             else if(k[i]>t[head]) total-=200,--tail;
             else
             {
                 for(j=tail,s=tail2;j>=head;--j,--s)
                 {
                      if(t[j]>k[s]) total+=200;
                      else
                      {
                          if(t[j]<k[i]) total-=200;
                          tail=--j;
                          tail2=s;
                          break;
                      }
                 }
             }
             if(head>tail) break;
         }
         printf("%d\n",total);
    }
}
