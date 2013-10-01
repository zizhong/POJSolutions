#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int len,n,t;
         scanf("%d%d",&len,&n);
         int early=0,last=0,m1,m2;
         for(int i=0;i<n;i++)
         {
              scanf("%d",&t);
              if(t<len-t) m1=t,m2=len-t;
              else m1=len-t,m2=t;
              if(early<m1) early=m1;
              if(last<m2) last=m2;
         }
         printf("%d %d\n",early,last);
    }
}
