#include<stdio.h>
int a[10001]={0},f[10001][100]={0};
main()
{
    int n,k,i=0,j=0;
    
    scanf("%d",&n);
    scanf("%d",&k);    
    for(i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
       while(a[i]<0)
           a[i]+=k;
       a[i]=a[i]%k;
    }
    f[0][0]=1;    
    f[1][a[1]%k]=1;
    for(i=1;i<=n;i++)
      for(j=0;j<k;j++)
      {
         if(f[i-1][j])
         {
            f[i][(j+a[i])%k]=1;
            f[i][(k+j-a[i])%k]=1;
         } 
      }
    if(f[n][0]) printf("Divisible\n");
    else printf("Not divisible\n");
    getchar();  getchar();  getchar();
}
