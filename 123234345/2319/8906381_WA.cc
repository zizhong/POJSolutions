#include<stdio.h>
int main()
{
    int F,R;
    while(scanf("%d-%d",&F,&R)==2)
    {
          int len,ten;
          for(len=1,ten=10;;len++,ten*=10)
          {
               int lf=F%ten,rf=R%ten;
               if(lf<rf && F-lf+rf == R || lf>=rf && F + ten - lf + rf == R)
               {
                      printf("%d-",F);
                      int x=len,y=rf;
                      while(y) x--,y/=10;
                      while(x--) putchar('0');
                      if(rf) printf("%d",rf);
                      puts("");
                      break;
               }
          }  
    }
}
