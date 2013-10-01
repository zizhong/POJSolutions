#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const int MAX=999999999;
int ss[9][9][9][9];
int f[9][9][9][9][16];
int cb[9][9];
int s[9][9];
int min(int a,int b)
{
    return a>b?b:a;
}
int sum(int x1,int y1,int x2,int y2,int n)
{
    if(n==1) return ss[x1][y1][x2][y2]*ss[x1][y1][x2][y2];
    if(f[x1][y1][x2][y2][n]) return f[x1][y1][x2][y2][n];
    int t=MAX;
    for(int a=x1;a<x2;a++)
    {
            t=min(t,sum(x1,y1,a,y2,n-1)+ss[a+1][y1][x2][y2]*ss[a+1][y1][x2][y2]);
            t=min(t,sum(a+1,y1,x2,y2,n-1)+ss[x1][y1][a][y2]*ss[x1][y1][a][y2]);
    }
    for(int b=y1;b<y2;b++)
    {
            t=min(t,sum(x1,y1,x2,b,n-1)+ss[x1][b+1][x2][y2]*ss[x1][b+1][x2][y2]);
            t=min(t,sum(x1,b+1,x2,y2,n-1)+ss[x1][y1][x2][b]*ss[x1][y1][x2][b]);
    }
    return f[x1][y1][x2][y2][n]=t;
}
int main()
{
     int n;
     scanf("%d",&n);
     for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
           scanf("%d",&cb[i][j]);
     for(int i=1;i<=8;i++)
          for(int j=1;j<=8;j++)
           s[i][j]=cb[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
     for(int x1=1;x1<=8;x1++)
     {
         for(int y1=1;y1<=8;y1++)
         {
             for(int x2=x1;x2<=8;x2++)
             {
                  for(int y2=y1;y2<=8;y2++)
                     ss[x1][y1][x2][y2]=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
             }
         }
     }
     int sm=sum(1,1,8,8,n);
     double r=sm*1.0/n-(s[8][8]*1.0/n)*(s[8][8]*1.0/n);
     printf("%.3f\n",sqrt(r));
     //system("pause");
}
