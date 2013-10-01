#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         int k=0,f1=0;
         for(int i=0;;i++)
         {
              if(n&(1<<i)) f1++;
              else if(f1)
                  {
                        k=i;
                        break;
                  }
         }
         f1--;
         int ans=0;
         for(int i=0;i<f1;i++)  ans|=(1<<i);
         ans|=(1<<k);
         for(int i=k+1;i<30;i++)
             ans|=n&(1<<i);
         printf("%d\n",ans);             
    }
}
