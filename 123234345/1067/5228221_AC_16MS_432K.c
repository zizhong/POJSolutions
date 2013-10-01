#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,k,temp,data;
    while(scanf("%d %d",&a,&b)==2)
          {
                if(a>b){
                    temp=b;
                    b=a;
                    a=temp;
                   }
                  k =b-a;
                  data=(floor)(k*(1.0+sqrt(5))/2.0);
                  if(a==data)
                      printf("%d\n",0);
                   else
                       printf("%d\n",1);
          }
          return 0;
}   
