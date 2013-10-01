#include<stdio.h>
int d[11];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=1;i<=n;i++)
             scanf("%d",&d[i]);
         if(n%2) {puts("1");continue;}
         int win=0;
         for(int i=1;i<n;i++) if(d[i])
         {
              int flag=0;
              for(int j=i+1;j<=n;j++) if(d[j]==d[i])
              {
                   flag=1;
                   d[j]=0;
                   break;
              }
              if(!flag){win=1;break;}
         }
         printf("%d\n",win);
    }
}
