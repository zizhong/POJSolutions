#include<stdio.h>
#define NIL 100000
int a[101][101],w[101][101],f[101];
main()
{
   int n,i,j,m,b,k,start,min;
   while(1)
   {
       scanf("%d",&n);
       if(!n) break;
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           a[i][j]=NIL;
       for(i=1;i<=n;i++)
       {
          scanf("%d",&m);
          while(m--)
              {scanf("%d",&j);
              scanf("%d",&a[i][j]);}           
       }
       for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
             w[i][j]=a[i][j];
      for(k=1;k<=n;k++)
         for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            w[i][j]=w[i][j]>(w[i][k]+w[k][j])?(w[i][k]+w[k][j]):w[i][j];
      for(i=1;i<=n;i++)
          f[i]=0;
       for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
            if(i!=j&&w[i][j]>f[i]) f[i]=w[i][j];
       
       min=NIL;
       for(i=1;i<=n;i++)
           if(f[i]&&f[i]<min) {start=i;min=f[i];}
      if(min>=NIL) printf("disjoint\n");
      else printf("%d %d\n",start,min);
   }
}
