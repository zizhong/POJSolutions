#include<stdio.h>
#include<string.h>
const int N=100001,inf=-0x7fffffff;
double d[N][5],m[N];
double getDouble()
{
      int d=0;
      char c;
      while((c=getchar())==' '||c=='\n') ;
      d=c-'0';
      double lv=1;
      while((c=getchar())>='0'&&c<='9') d=d*10+c-'0';
      if(c=='.')
      {
           while((c=getchar())>='0'&&c<='9') d=d*10+c-'0',lv*=0.1;
      }
      return d*lv;
}
void putDouble(double x)
{
     x*=100;
     int d=(int)(x+0.5);
     printf("%d.%d%d\n",d/100,d/10%10,d%10);
}
int main()
{
    double ans=inf;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       for(int j=0;j<5;j++)
          d[i][j]=getDouble();
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
    putDouble(ans);
}
