#include<stdio.h>
int main()
{
    int step,mod;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
         int a[100001]={0};
         int i,j,seed=0;
         for(j=0;;j++)
         {
            if(a[seed]) break;
            a[seed]=1;
            seed=(seed+step)%mod;
         }
         printf("%10d%10d    ",step,mod);
         if(j==mod) printf("Good Choice\n\n");
         else printf("Bad Choice\n\n");
    }   
}
