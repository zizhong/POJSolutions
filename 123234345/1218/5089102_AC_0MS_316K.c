#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n,i,j,m=0;
       int a[101]={0};
       scanf("%d",&n);
       for(i=1;i<n;i++)
          for(j=i+1;j<=n;j+=i+1)
            if(a[j]) a[j]=0;
            else a[j]=1;
      for(i=1;i<=n;i++)
         if(a[i]) m++;
      printf("%d\n",n-m);
    }
}
