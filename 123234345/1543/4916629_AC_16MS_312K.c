#include<stdio.h>
long a[101];
main()
{
    int n,i,j,k,r,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        a[i]=i*i*i;
    for(i=6;i<=n;i++)
       for(j=2;j<i-1;j++)
          for(k=j+1;k<i;k++)
          {
              x=a[i]-a[j]-a[k];
             if(x>=a[k])
               for(r=k;x>=a[r];r++)
                if(x==a[r])
                   printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,r);
          }
}
