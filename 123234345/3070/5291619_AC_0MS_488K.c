#include<stdio.h>
#define MAX 15000
int fi[MAX+1];
void Fibo()
{
     int f1=0,f2=1,t,i;
     fi[0]=0,fi[1]=1;
     for(i=2;i<=MAX;i++)
     {
        f1=(f1+f2)%10000;
        t=f1,f1=f2,f2=t;
        fi[i]=f2;
     }
}
int main()
{
   int n;
   Fibo();
   while(scanf("%d",&n)&&n!=-1)
      printf("%d\n",fi[n%15000]);
}
