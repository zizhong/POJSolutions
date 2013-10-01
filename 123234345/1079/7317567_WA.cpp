#include<stdio.h>
#include<math.h>
int main()
{
    int d1,d2;
    while(scanf("%d%d",&d1,&d2)==2)
    {
          double err=1e10;
          double xx=d1*1.0/d2;
          for(int i=1;i<=d2;i++)
          {
               int x=d1*i/d2;
               if(fabs(x*1.0/i-xx)<fabs((x+1)*1.0/i-xx)&&fabs(x*1.0/i-xx)+1e-8<err)
               {
                   err=fabs(x*1.0/i-xx);
                   printf("%d/%d\n",x,i);
               }
               else if(fabs(x*1.0/i-xx)>fabs((x+1)*1.0/i-xx)&&fabs((x+1)*1.0/i-xx)+1e-8<err)
               {
                   err=fabs((x+1)*1.0/i-xx);
                   printf("%d/%d\n",x+1,i);
               }
          }
          puts("");
    }
}
