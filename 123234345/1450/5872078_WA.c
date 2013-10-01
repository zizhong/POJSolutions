#include<stdio.h>
int main()
{
   int total,m,n,i;
   scanf("%d",&total);
   for(i=1; i <= total ; i++)
  {
     scanf("%d%d",&m,&n);
     printf("Scenario #%d:\n",i);
   if( (m*n)&1== 0)
      printf("%d.00\n",m*n);
   else
    printf("%d.41\n",m*n);
   printf("\n");
  }
}
