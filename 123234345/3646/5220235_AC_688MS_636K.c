#include<stdio.h>
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
       int i,j,h[20000]={0},k[20000]={0},mark[20000]={0},flag=0;
       for(i=0;i<n;i++)
          scanf("%d",&h[i]);
       for(i=0;i<m;i++)
          scanf("%d",&k[i]);
       qsort(h,n,sizeof(int),cmp);
       qsort(k,m,sizeof(int),cmp);
       for(i=0;i<n;i++)
       {
          int mj=-1,min=999999999;
          for(j=0;h[i]<=k[j]&&j<m;j++)
           if(k[j]<min&&!mark[j]) min=k[j],mj=j;
          if(mj==-1) {flag=1; break;}
          mark[mj]=1;
       }
       if(flag) printf("Loowater is doomed!\n");
       else
       {
           int sum=0;
           for(i=0;i<m;i++)
             if(mark[i]) sum+=k[i];
           printf("%d\n",sum);
       }
    }
}
