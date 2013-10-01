#include<stdio.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int a[1001];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
       int r=0,i;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
          scanf("%d",&a[i]);
       qsort(a,n,sizeof(int),cmp);
       for(i=1;i<=n;i++)
          r^=(a[i]-a[i-1]-1);
       if(!r) printf("Bob will win\n");
       else printf("Georgia will win\n");
    }
}
