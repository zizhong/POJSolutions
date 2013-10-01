#include<stdio.h>
#define NMAX 9999999
int a[1001][1001],n,t,f[3][1001];
main()
{
    int i,j,min,tail;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       if(i!=j) a[i][j]=NMAX;
    while(t--)
      { 
      scanf("%d%d",&i,&j);
      scanf("%d",&a[i][j]);
      a[j][i]=a[i][j];
      }
    f[2][1]=1;
    for(i=1;i<=n;i++)
    {
        f[0][i]=a[1][i];
        f[1][i]=1;
    }
    while(1)
    {
        min=NMAX;
        for(i=1;i<=n;i++)
          if(f[2][i]==0&&min>f[0][i])
          {
             min=f[0][i];
             tail=i;
          }
        f[2][tail]=1;        
        for(i=1;i<=n;i++)
        if(f[2][i]==0&&f[0][i]>f[0][tail]+a[tail][i])
        {
           f[0][i]=f[0][tail]+a[tail][i];
           f[1][i]=tail;
        }
        if(f[2][n]) {printf("%d\n",f[0][n]);break;}
    }
}
