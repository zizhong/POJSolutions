#include<stdio.h>
#include<stdlib.h>
int i,p,q,pt,a,b;
int main()
{
    while (scanf("%d%d",&a,&b)!=-1)
    {
          p=1;q=0;
          for (i=1;i<=b;i++)
          {
              pt=(double)(i*a)/(double)b+0.5;
              if (q*abs(a*i-b*pt)<i*abs(a*q-b*p)) {p=pt;q=i;printf("%d/%d\n",p,q);}
              if (a*q==b*p) break;
          }
          puts("");
    }
}
    
