#include<stdio.h>
int a[100],r[100],len,d[202];
int n;
void initialize();
void print();
void dfs(int l);
main()
{
    while(scanf("%d",&n)&&n)
    {
    initialize();
    if(n==2)
    {
       printf("1 2\n");
       continue;
    }
    if(n==3)
    {
      printf("1 2 3\n");
      continue;
    }
    dfs(2);
    print();
    }
}
void initialize()
{
   int i;
   len=n;
   a[1]=1;
   a[2]=2;
   for(i=n;i<=n+n;i++)
      d[i]=0;
   for(i=n-1;i>0;i--)
      d[i]=d[i+i]+1;   
}
void print()
{
   int i=0;
   for(i=1;i<len;i++)
      printf("%d ",r[i]);
   printf("%d\n",n);
}
void dfs(int l)
{
    int i,j;
    if(l+d[a[l]]>=len) return ;
    if(a[l]==n)
    {
      for(i=1;i<=l;i++)
         r[i]=a[i];
      len=l;
      return ;
    }
    for(i=l;i>=0;i--)
       for(j=i;j>=0;j--)
      {
         a[l+1]=a[i]+a[j];
         if(a[l+1]>a[l]&&a[l+1]<=n)
            dfs(l+1);
      }
}
