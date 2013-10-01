#include <stdio.h>
#include<math.h>
int main()
{
    double x[4],y[4];
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
    {
          int mi=-1;
          for(int i=0;i<4;i++)
          {
               for(int j=i+1;j<4;j++)
                    if(fabs(x[i]-x[j])<1e-8&&fabs(y[i]-y[j])<1e-8)
                    {
                         mi=i;
                         break;
                    }
               if(mi!=-1) break;
          }
          double hx=x[0]+x[1]+x[2]+x[3],hy=y[0]+y[1]+y[2]+y[3];
          hx-=2*x[mi],hy-=2*y[mi];
          printf("%.3f %.3f\n",hx-x[mi],hy-y[mi]);
    }
}
