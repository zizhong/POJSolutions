#include<stdio.h>
#include<math.h>
#include<string.h>
const int M = 45;
const double INF = 1000000000;
double dp[2][M][M];
bool f=0;
struct Node
{
 double x[M],y[M];
 int len;
 void In()
 {
  scanf("%d",&len);
  int i;
  for(i=0;i<len;i++)
   scanf("%lf%lf",&x[i],&y[i]);
 }
}cow[105];
int n;
double Dis(int ni,int nj,int li,int lj)
{
 double a=cow[ni].x[li]-cow[nj].x[lj];
 double b=cow[ni].y[li]-cow[nj].y[lj];
 return sqrt(a*a+b*b);
}

void DP()
{
 int i,j,k,jj;
 double temp;
 for(k=0;k<=1;k++)
 for(i=0;i<M;i++)
 for(j=0;j<M;j++)
  dp[k][i][j]=INF;

 for(i=0;i<cow[0].len;i++)
  dp[f][i][i]=0;
 for(i=1;i<n;i++)
 {
  for(jj=0;jj<cow[0].len;jj++)
  {
   for(j=0;j<cow[i].len;j++)
   {
    dp[!f][jj][j]=INF;
    for(k=0;k<cow[i-1].len;k++)
    {
     temp=dp[f][jj][k]+Dis(i-1,i,k,j);
     if(temp<dp[!f][jj][j])dp[!f][jj][j]=temp;
    }
   }
  }
  f=!f;
 }
}
int main()
{
 scanf("%d",&n);
 {
  int i,j;
  for(i=0;i<n;i++)
   cow[i].In();
  DP();
  double min=INF,temp;
  for(i=0;i<cow[0].len;i++)
  {
   for(j=0;j<cow[n-1].len;j++)
   {
    temp=dp[f][i][j]+Dis(0,n-1,i,j);
    if( temp<min )min=temp;
   }
  }
  int re=min*100+1e-8;
  printf("%d\n",re);
 }
}
