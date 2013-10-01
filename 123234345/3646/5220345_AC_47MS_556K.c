#include<stdio.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
       int i=0,j=0,h[20000]={0},k[20000]={0},sum=0,flag=0;
       for(i=0;i<n;i++)
          scanf("%d",&h[i]);
       for(i=0;i<m;i++)
          scanf("%d",&k[i]);
       if(n>m)  {printf("Loowater is doomed!\n");continue;}
       qsort(h,n,sizeof(int),cmp);
       qsort(k,m,sizeof(int),cmp);
       for(i=0;i<n;i++)
       {
          while(k[j]<h[i]) j++;
          if(j>=m) {flag=1; break;}
          sum+=k[j++];
       }
       if(flag) printf("Loowater is doomed!\n");
       else printf("%d\n",sum);
    }
}
