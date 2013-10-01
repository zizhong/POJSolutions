#include<stdio.h>
main()
{
      double r,m;
      int y;
      scanf("%lf%lf%d",&r,&m,&y);
      r=0.01*r+1;
      while(y--)
         m*=r;
      printf("%d\n",(int)m);}
