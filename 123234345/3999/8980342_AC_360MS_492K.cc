#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n,m,nn;
double b[101];
double a[101][101];
double x[101];
void solve()
{
     int i,j,k;
     for(int h=0;h<nn-1;h++)
     {
          int mi=h;
          for(i=h+1;i<=nn;i++)
             if(fabs(a[mi][h])<fabs(a[i][h]))
                  mi=i;
          for(i=0;i<=nn;i++)
          {
               double t=a[h][i];
               a[h][i]=a[mi][i];
               a[mi][i]=t;
          }
          for(i=h+1;i<nn;i++)
          {
               double wa=a[h][h],wb=a[i][h];
               for(j=h;j<=nn;j++)
               {
                   a[i][j]=a[i][j]*wa - a[h][j]*wb;
                   a[i][j]/=fabs(wa);
               }
          }
     }
     memset(x,0,sizeof(x));
     for(i=nn-1;i>=0;i--)
     {
             x[i]=a[i][nn];
             for(j=nn-1;j>i;j--)
                  x[i]-=a[i][j]*x[j];
             x[i]/=a[i][i];
     }
     for(i=0;i<nn;i++)
     {
          
          printf("%8.2f",x[i]);
          if((i+1)%m==0) puts("");
     }
}
int main()
{
    int nb;
    int T=0;
    while(scanf("%d%d%d",&m,&n,&nb),n+m+nb)
    {
         if(T) puts("");
         nn=n*m;
         memset(a,0,sizeof(a));
         for(int i=0;i<nn;i++)
                   scanf("%lf",&b[i]);
         int nk[101]={0};
         for(int i=0;i<nn;i++)
             for(int j=0;j<nn;j++)
                   if(abs(i/m-j/m)+abs(i%m-j%m)<=nb)
                   {
                          a[i][j]=1;
                          nk[i]++;
                   }
         for(int i=0;i<nn;i++)
              a[i][nn]=b[i]*nk[i];
         solve(); 
         T++;        
    }
}