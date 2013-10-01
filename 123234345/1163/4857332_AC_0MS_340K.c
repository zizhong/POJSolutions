#include<stdio.h>
int a[101][101];
main()
{
    int n,i,j,max;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)
          scanf("%d",&a[i][j]);  
    for(i=2;i<=n;i++)
     {      
       for(j=1;j<=i;j++)
       {
          if(a[i-1][j-1]>a[i-1][j])
               a[i][j]+=a[i-1][j-1];
          else a[i][j]+=a[i-1][j];
       }
     }
     max=0;
     for(i=1;i<=n;i++)
        if(max<a[n][i]) max=a[n][i];
     printf("%d\n",max); 
}
