#include<stdio.h>
#define N 1299710
short a[2][N];
int prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
       if(!n%i) return 0;
    return 1;
}
int main()
{
    int i,j,n;
   for(i=0;i<N;i++)
    {  if(!a[1][i])
      {
          a[1][i]=1;
          if(i<2) a[0][i]=i;
          else
          {
              if(prime(i)) a[0][i]=1;
              else a[0][i]=0;
              for(j=2*i;j<N;j+=i)
                 a[1][j]=1,a[0][j]=0;
          }
      }
    }
    while(scanf("%d",&n)&&n)
    {
       if(a[0][n])
         printf("0\n");
       else
       {
          for(i=n;!a[0][i];i++);
          for(j=n;!a[0][j];j--);
          printf("%d\n",i-j);
       }
    }
}
