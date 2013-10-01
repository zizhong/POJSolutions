#include<stdio.h>
#include<string.h>
const int N=100001,inf=-0x7fffffff;
double d[N][5],m[N];
int main()
{
    double ans=inf;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       for(int j=0;j<5;j++)
          scanf("%lf",&d[i][j]);
    for(int k=0;k<(1<<5);k++)
    {
          for(int i=0;i<n;i++)
          {
              m[i]=0;
              for(int j=0;j<5;j++)
              if(k&(1<<j))
                   m[i]+=d[i][j];
              else m[i]-=d[i][j];
          }
          double max1=inf,max2=-inf;
          for(int i=0;i<n;i++)
             if(m[i]>max1) max1=m[i];
          for(int i=0;i<n;i++)
             if(m[i]<max2) max2=m[i];
          if(ans<max1-max2) ans=max1-max2;
    }
    printf("%.2f\n",ans);
}
