#include<stdio.h>
const int N=10000;
int d[N],td[N];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
              scanf("%d",&d[i]);
         int tt,can;
         for(tt=0;;tt++)
         {
             int flag=1;
             can=d[0];
             for(int i=1;i<n;i++) if(can!=d[i])
                 flag=0;
             if(flag) break;
             for(int i=0;i<n;i++)
                 td[i]=d[i]/2+d[(i-1+n)%n]/2;
             for(int i=0;i<n;i++)
             {
                d[i]=td[i];
                if(d[i]&1) d[i]++;
             }
         }
         printf("%d %d\n",tt,can);
    }
}
