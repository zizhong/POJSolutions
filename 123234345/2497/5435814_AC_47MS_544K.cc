#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    int t=ncase;
    while(t--)
    {
       printf("Scenario #%d:\n",ncase-t);
       int ct,n;
       scanf("%d%d",&ct,&n);
       int a[25]={0};
       for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
       int p,tm=0;
       qsort(a,n,sizeof(a[0]),cmp1);
       int k;
       for(k=0;k<n&&ct>=a[k];k++) ct-=a[k];
       p=k;
       for(int i=1;i<n;i++) a[i]+=a[i-1];
       for(int i=0;i<k;i++) tm+=a[i];
       
       printf("Steve wins with %d solved problems and a score of %d.\n\n",p,tm);
       
       
    }
}
