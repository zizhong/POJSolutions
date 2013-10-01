#include<stdio.h>
int stamp[1001];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int t,h;
    scanf("%d",&t);
    h=t;
    while(t--)
    {
       int ns,nf,i,nl=0;
       scanf("%d%d",&ns,&nf);
       for(i=0;i<nf;i++)
          scanf("%d",&stamp[i]);
       qsort(stamp,nf,sizeof(stamp[0]),cmp);
       for(i=0;i<nf&&(ns-=stamp[i])>0;i++);
       printf("Scenario #%d:\n",h-t);
       if(i<nf) printf("%d\n\n",i+1);
       else printf("impossible\n\n");
    }
}
