#include<stdio.h>
short a[101][101],b[101];
int f[101][101],bf[101];
void zip(int j,int k,int n)
{
    int i=1,p;
    for(i=1;i<=n;i++)
        b[i]=0;
    for(i=1;i<=n;i++)
       for(p=j;p<=k;p++)
          b[i]=b[i]+a[p][i];
}
int maxi(int n)
{
    int max=0,i;
    bf[1]=b[1];
    for(i=2;i<=n;i++)
       bf[i]=bf[i-1]>0?bf[i-1]+b[i]:b[i];
    for(i=1;i<=n;i++)
        max=max<bf[i]?bf[i]:max;
    return max;
}
main()
{
    int n,i,j,k,max;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
      for(j=i;j<=n;j++)
      {
         zip(i,j,n);
         f[i][j]=maxi(n);
      }
    max=0;
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       max=max>f[i][j]?max:f[i][j];
    printf("%d\n",max);}
