#include<stdio.h>
main()
{
      int n;
      printf("PERFECTION OUTPUT\n");
      while(scanf("%d",&n)&&n)
      {
      int i,sum=1;
      for(i=2;i<=sqrt(n);i++)
         if(n%i==0){
                      sum+=i+n/i;
                      if(i==n/i) sum-=i;
                   }
      printf("%5d  ",n);
      if(n==1||sum<n) printf("DEFICIENT\n");
      else if(sum==n) printf("PERFECT\n");
      else if(sum>n) printf("ABUNDANT\n");
      }
      printf("END OF OUTPUT\n");
}
