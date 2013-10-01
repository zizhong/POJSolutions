#include<stdio.h>
#define MAX 99999999
int a[101][101];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    int i,j,k,min=0;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(i!=j) a[i][j]=MAX;
    for(i=2;i<=n;i++)
       for(j=1;j<i;j++)
       {
          char s[15]={0};
          scanf("%s",s);
          if(s[0]!='x')
             sscanf(s,"%d",&a[i][j]);
          a[j][i]=a[i][j];
       }
   for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)        
        if(a[i][j]>a[i][k]+a[k][j])
           a[i][j]=a[i][k]+a[k][j];
    for(i=2;i<=n;i++)
      if(a[1][i]>min) min=a[1][i];
     printf("%d\n",min);
   }
}

